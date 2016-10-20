#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

class HashNode
{
public:
    int key;
    int value;
    HashNode * next;
};

class HashMap
{
public:
    int cout[20001];
    HashNode * head[20001];
    void add_table(long int& in);
};

void HashMap::add_table(long int& in)
{
    int key;
    int value;
}
