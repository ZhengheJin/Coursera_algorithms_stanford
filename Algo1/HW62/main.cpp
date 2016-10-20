#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <set>

using namespace std;


bool hasher(int i, set<long int> work)
{
    for(set<long int>::iterator itr=work.begin();itr!=work.end();++itr)
    {
        if(work.find(i-(*itr))!=work.end())
            return true;
    }

    return false;

}


int main()
{
    ifstream file;
    ifstream in("algo1.txt", ios::in);
typedef set<long int> hset;
		string str;
	long int input=0;
	int count=0;
	int i=0;

	hset work={};

	while(getline(in,str))
    {
        count++;
			istringstream ss(str);
			ss>>input;
//			cout<<input<<endl;
        work.insert(input);
    }

    cout<<count<<endl;

	for(hset::iterator itr=work.begin();itr!=work.end();++itr)
	{
		cout<<(*itr)<<endl;
		++i;
		if(*itr>10000)break;
	}

	cout<<"1:"<<endl;

    count = 0;
    for(int i=-10000;i<=10000;i++)
    {
        if(hasher(i, work))
            count++;
    }

	cout<<count<<endl;

    return 1;
}
