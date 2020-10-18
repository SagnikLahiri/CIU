#include<iostream>

using namespace std;

int main()
{
    int n=3,pos=3,ele=8,i=0;
    int *arr = new int(4);
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;

    for(i=n;i>pos-1;i--)
        arr[i]=arr[i-1];
        arr[i]=ele;

     for(i=0;i<4;i++)
     cout<<arr[i]<<endl;
}