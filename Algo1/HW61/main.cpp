#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <set>

using namespace std;

typedef set<long long int> hset;

bool hasher(int i, hset work)
{
    for(hset::iterator itr=work.begin();itr!=work.end();++itr)
    {
        if(work.find(i-(*itr))!=work.end())
            return true;
    }

    return false;

}
int main()
{
    ifstream file;
    ifstream in("algo1-programming_prob-2sum.txt", ios::in);
	long long int input;
	int count=0;


	hset work={};

	while(in>>input)
    {
        work.insert(input);
    }

    for(int i=-10000;i<=10000;i++)
    {
        if(hasher(i, work)== true)
            count++;
    }

	cout<<count<<endl;

    return 1;
}
