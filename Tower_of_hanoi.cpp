#include<bits/stdc++.h>
using namespace std;


void Tower_modified(int n,char T1,char T2,char T3)
{
    if(n>0)
    {
        Tower_modified(n-1,T1,T3,T2);
        cout<<"( "<<T1<<" -> "<<T3<<" ) "<<endl;
        Tower_modified(n-1,T2,T1,T3);
    }
}

void Tower(int n,char T1,char T2,char T3)
{
    if(n>0)
    {
        Tower(n-1,T1,T3,T2);
        cout<<"( "<<T1<<" -> "<<T2<<" ) "<<endl;
        Tower(n-1,T3,T2,T1);
    }
}
int main()
{
    int n;
    cout<<"Enter no of disks : ";
    cin>>n;
    Tower_modified(n,'A','B','C');
}