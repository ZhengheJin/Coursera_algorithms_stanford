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
    ifstream in("input", ios::in);
	long int i;

	while(in>>i)
    {
			cout<<i<<endl;
    }

	return 1;
}
