#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "graph.h"

using namespace std;

int main()
{
    graph g;
    ifstream file;
    ifstream in("dijkstraData.txt", ios::in);
	string str;

	int i=0,j=0,k=0;
	char c;
	while(getline(in,str))
	{
		++i;
		g.addvertex(i);

		istringstream ss(str);
		ss>>j;//read head //构造字符串流的时候，空格会成为字符串参数的内部分界
		while(ss>>j) //read node
		{
			ss>>c; //read ','
			ss>>k; //read distance
			cout<<j<<","<<k<<" ";
			g.addvertex(j);
			g.addedge(i,j,k);
		}

		cout<<endl;
	}


    /*int i,j,k;
	in>>j;
	for(i=1;i<=200;i++)
	{
		cout<<"i"<<i<<"   ";
		g.addvertex(i);
		while(in>>j)
		{
		if(j==i+1)
		{
			cout<<endl;
			break;
		}
		if(j>200 or j<0)
		cout<<j<<",";
		g.addvertex(j);
		in>>k;
		cout<<k<<" ";
		g.addedge(i,j,k);
		}
	}


	//the key of the transpose map, by creating new map with {new keys,old value}
	//o(m)

   // g_t2.printGraph();
	//cout<<endl;
*/

	//g.printGraph();

	const int ii=1;
	g.dijkstra(ii);
	g.printGraph();
    return 1;
}
