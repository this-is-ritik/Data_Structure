#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX



// detect the negative weight edge cycle in graph
// time complexity is O(n*m)

bool bellman_ford(vector<pair<int,pair<int,int>>>adj,int n,int x)
{
    int*distance=new int[n];
    memset(distance,INF,sizeof(distance));
    distance[x]=0;
    // O(n-1)
    for(int i=1;i<n;++i)
    {
        // O(m)
        for(auto e:adj)
        {
            int a,b,w;
            a=e.first;
            b=e.second.first;
            w=e.second.second;
            distance[b]=min(distance[b],distance[a]+w);
        }
    }

    // checking negative edge cycle
    // O(m)
    for(auto e:adj)
    {
        int a,b,w;
        a=e.first;
        b=e.second.first;
        w=e.second.second;
        if(distance[a]+w<distance[b])
            return true;
    }
    return false;
}
int main()
{
    int V;
    cout<<"Enter no of vertices : ";
    cin>>V;
    vector<pair<int,pair<int,int>>>adj;
    int choice;
    cout<<"if you dont want to enter edge then just enter a vertex value out of bound i.e.(-ve or >=n)\n";
    do
    {
        int i,j,w;
        cout<<"Enter starting vertex : ";
        cin>>i;
        cout<<"Enter ending vertex : ";
        cin>>j;
        cout<<"Enter weight of vertex : ";
        cin>>w;
        if(i<0 or i>V-1 or j<0 or j>V-1)
            break;
        adj.push_back(make_pair(i,make_pair(j,w)));
    }while(choice!=-1);
    int x=0;
    bool test=bellman_ford(adj,V,x);
    cout<<"'Negative weight cycle Present' is proved to be "<<((test==1)?"true":"false")<<endl;
}