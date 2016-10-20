#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

enum Color {BLACK, GRAY, WHITE};


struct vertex{  
	//vertex {name,dtime,ftime,color, parent etc. vector<distance, vertex *t> }
	//represent graph by adjacancy list
    typedef pair<int,vertex*> ve;
    class graph;
    vector<ve> adj; //cost of edge, destination vertex
    int name;
    int dtime,ftime,record;
    Color color;
    vertex* parent;
    vertex(int s,int rec=0,int dt=0, int ft=0, Color cl=WHITE, vertex* pt=NULL)
    {
        name=s;
        dtime=dt;  //DFS
        ftime=ft;  //DFS
        color=cl;  //DFS
        parent=pt; // DFS
        record=rec;// record number from first time DFS
    }
    void printVertex();
};

void vertex::printVertex() //print out vertex information
{
    cout<<name;
    vector<ve>::iterator it=adj.begin();
    while(it!=adj.end())
    {
        cout<<"->"<<it->second->name;
        ++it;
    }
    cout<<endl;
    cout<<dtime<<" "<<ftime<<" "<<record<<endl;
}

class graph
{
    public:
        typedef map<int, vertex *> vmap;
        vmap work;
        void addvertex(const int&, const int&);
        void addedge(const int& from, const int& to, int cost=1);
        void printGraph();
        void SCC();
        void DFS_VISIT(vertex *, int &);
        void DFS();
        void DFS_2();
        void treehead();
        graph changemap();
        graph create_transpose();
        vertex* find_max_rec_WHITE();
};

graph graph::changemap()
{
	graph g_t;
	
	vmap::iterator itr=work.begin();
    while(itr!=work.end())
    {
       int i=itr->second->record*(-1);
       vertex *t=itr->second;
       g_t.work.insert({i,t});
       ++itr;
    }
    
    return g_t;
}

void graph::addvertex(const int &name,const int &rec=0)
{
    vmap::iterator itr=work.begin();
    itr=work.find(name);
    if(itr==work.end())
    {
        vertex *v;
        v= new vertex(name,rec);
        work[name]=v;
        return;
    }
        //cout<<"\nVertex already exists!";
}

void graph::addedge(const int& from, const int& to, int cost)
{
    vertex *f=(work.find(from)->second);
    vertex *t=(work.find(to)->second);
    pair<int,vertex *> edge = make_pair(cost,t);
    f->adj.push_back(edge);
}

void graph::printGraph()
{
    vmap::iterator itr=work.begin();
    while(itr!=work.end())
    {
       // cout<<itr->first<<endl; //print key, key can be any infomation of the vertex
        vertex *v=itr->second;
        v->printVertex();  //print each vertex
        ++itr;
    }
}

graph graph::create_transpose()
{
    graph g_t;
    vmap::iterator itr=work.begin();
    while(itr!=work.end())
    {
       // cout<<itr->first<<endl;
        vertex *f=itr->second;
        vector<pair<int,vertex*> >::iterator it=f->adj.begin();
        //pair<int,vertex *> edge=make_pair(it->,t)
        while(it!=f->adj.end())
        {
            vertex *t=it->second;
            int cost=it->first;
            g_t.addvertex(f->name, f->ftime);
            g_t.addvertex(t->name, t->ftime);
            g_t.addedge(t->name,f->name,cost);

            ++it;
        }
        ++itr;
    }

    return g_t;
}

void graph::SCC()
{
    DFS();
    //printGraph();
    cout<<endl;
    graph g_t=create_transpose();
    //g_t.printGraph();
    g_t.DFS();

    cout<<endl;

    //g_t.printGraph();

    g_t.treehead();
}
void graph::DFS_VISIT(vertex* u, int& time)
{
    ++time;
    u->dtime=time;
    u->color=GRAY;
    for(vector<pair<int,vertex*> >::iterator it=u->adj.begin();it!=u->adj.end();++it)
    {
        if(it->second->color==WHITE)
        {
            it->second->parent=u;
            DFS_VISIT(it->second,time);
        }
    }
    u->color=BLACK;
    ++time;
    u->ftime=time;
}
void graph::DFS()
{
    int time=0;
    for(vmap::iterator itr=work.begin();itr!=work.end();++itr)
    {
        if(itr->second->color==WHITE)
            DFS_VISIT(itr->second, time);
    }
}
void graph::DFS_2()
{
    int time=0;
    graph::find_max_rec_WHITE();

    vertex* u;
    for(vmap::iterator itr=work.begin();itr!=work.end();++itr)
    {
        u=find_max_rec_WHITE();
        if(u->color==WHITE)
            DFS_VISIT(u, time);
    }
}

vertex* graph::find_max_rec_WHITE()
{
    int max=-1;
    vmap::iterator itr=work.begin();
    vertex* u=itr->second;
    for(; itr!=work.end();++itr)
    {
        if(itr->second->color==WHITE && itr->second->record>max)
        {
            max=itr->second->record;
            u=itr->second;
        }
    }

    return u;
}


void graph::treehead()
{
    for(vmap::iterator itr=work.begin();itr!=work.end();++itr)
    {
        if(itr->second->parent==NULL)
            cout<<itr->second->name<<" "<<(1+(itr->second->ftime)-(itr->second->dtime))/2<<endl;
    }

}
