#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "graph.h"

using namespace std;

int main()
{
    graph g;
    ifstream file;
    ifstream in("SCC.txt", ios::in);

    int i,j;

    while(in>>i)
    {
        in>>j;
        g.addvertex(i);
        g.addvertex(j);
        g.addedge(i,j);
    }

    g.DFS(); //DFS, write to discover time, finish time. //o(m)
    //g.printGraph();
    //cout<<endl;

    graph g_t=g.create_transpose();//create transpose time, copy g.ftime to g_t.record ( used for sorting )
    //g_t.printGraph();
    //g_t.DFS_2(); //DFS by maximum record, o(nm)
    //cout<<endl;

	graph g_t2=g_t.changemap(); //map keep item sorted by key, so change
	//the key of the transpose map, by creating new map with {new keys,old value}
	//o(m)

   // g_t2.printGraph();
	//cout<<endl;

	g_t2.DFS(); //o(m)
    g_t2.treehead(); //post process, print out the SCC number

    return 1;
}
