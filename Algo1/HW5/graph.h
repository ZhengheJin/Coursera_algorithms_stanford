#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

enum Color {BLACK, GRAY, WHITE};


struct vertex{
	//vertex {name,dtime,ftime,color, parent etc. vector<distance, vertex *t> }
	//represent graph by adjacancy list
    typedef pair<int,vertex*> ve;
    class graph;
    vector<ve> adj; //cost of edge, destination vertex
    int name;
    int distance;
    Color color;
    vertex* parent;
    vertex(int s,int ds=6000000, Color cl=WHITE, vertex* pt=NULL)
    {
        name=s;
		distance=ds;
		color=cl;
        parent=pt;
    }
    void printVertex();
};

void vertex::printVertex() //print out vertex information
{
    cout<<name;
    vector<ve>::iterator it=adj.begin();
    while(it!=adj.end())
    {
        cout<<"->"<<it->second->name<<","<<it->second->distance<<" ";
        ++it;
    }
    cout<<endl;
	cout<<name<<" "<<distance<<endl;
}

class graph
{
    public:
        typedef map<int, vertex *> vmap;
        vmap work;
        void addvertex(const int&);
        void addedge(const int& from, const int& to, int);
		void dijkstra(const int& from); //change the distance data
		int  ExtractMin(set<int>);
		void Relax(const int&, const int&);
		void printGraph();
};

void graph::addvertex(const int &name)
{
    vmap::iterator itr=work.begin();
    itr=work.find(name);
    if(itr==work.end())
    {
        vertex *v;
        v= new vertex(name);
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

void graph::dijkstra(const int& s)
{
	set<int> S={};
	set<int> Q={};

	for(vmap::iterator itr=work.begin();itr!=work.end();++itr)
		Q.insert(itr->first);


	work[s]->distance=0;
	printGraph();
	while(Q.size())
	{
		int u=ExtractMin(Q);
		S.insert(u);
		Q.erase(u);
	//cout<<"Extraction done, minimum u is"<<u<<endl;
		for(vector<pair<int,vertex*> >::iterator it=work[u]->adj.begin();it!=work[u]->adj.end();++it)
		{
			Relax(u,it->second->name);
		}
	}

}

int graph::ExtractMin(set<int> Q)
{
	int minimum=1000000;
	int c=0;

	for(set<int>::iterator itr=Q.begin();itr!=Q.end();++itr)
	{
		if(work[*itr]->color==WHITE&&work[*itr]->distance<minimum)
		{
			c=*itr;
			minimum=work[*itr]->distance;
		}

	}
	work[c]->color=BLACK;
	return c;
}

void graph::Relax(const int& u, const int& v)
{
	int uv=1000000;
	for(vector<pair<int,vertex*> >::iterator it=work[u]->adj.begin();it!=work[u]->adj.end();++it)
	{
		if(it->second->name==v)
		{
			uv=it->first;
			//cout<<"uv found, uv distance="<<u<<" "<<v<<" "<<uv<<endl;
			//cout<<"u v distance="<<work[u]->distance<<" "<<work[v]->distance<<" "<<uv<<endl;
		}
	}
	if(uv==1000000)return;
	if(work[v]->distance>work[u]->distance+uv)
	{
		//cout<<"relax done"<<endl;
		work[v]->distance=work[u]->distance+uv;
		work[v]->parent=work[u];
	}
}

