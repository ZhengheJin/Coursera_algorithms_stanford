#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <map>

using namespace std;


void swap(int arr[], int i, int j)
{
    int tmp;
    tmp = arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}
int max(int i,int j, int k)
{
    int t = i>j? i: j;
    return t>k? t : k;
}

int min(int i,int j, int k)
{
    int t = i<j? i: j;
    return t<k? t : k;
}

int Partition(int arr[], int p, int r)
{
    int x = arr[p];
    //int x = arr[p]+arr[r]+arr[(p+r)/2]-max(arr[p],arr[r],arr[(p+r)/2])-min(arr[p],arr[r],arr[(p+r)/2]);// different by different condition
    int i = p+1;
    for(int j=p+1; j<=r; j++)
    {
        if(arr[j]<x)
        {
            swap(arr,i,j);
            i++;
        }
    }
    swap(arr,i-1,p);
    return i-1;
}
unsigned long QuickSort(int arr[], int p, int r)
{
    if(p<r)
    {
        int x = arr[p]+arr[r]+arr[(p+r)/2]-max(arr[p],arr[r],arr[(p+r)/2])-min(arr[p],arr[r],arr[(p+r)/2]);
        if(x == arr[r])
            swap(arr, p, r);
        else if( x == arr[p])
            ;
        else
            swap(arr,p,(p+r)/2); //case 3
//        swap(arr,p,r); //case 2
        int q = Partition(arr,p,r);
        return(QuickSort(arr,p,q-1)+QuickSort(arr,q+1,r)+r-p);
    }
    else
        return 0;

}
int main(int argv, char** args)
{
  int arr[10000] = {0};
  ifstream file;
  ifstream in("QuickSort.txt", ios::in);
  for(int i=0;i<100000;i++)
  {
      in >> arr[i];
  }
//  // test input file
//    for(int i=0;i<10;i++)
//  {
//      cout << arr[i] <<endl;
//  }
  cout << QuickSort(arr, 0, 10000-1)<<endl;
  return 0;
}
