#include<bits/stdc++.h>
using namespace  std;
#define INF INT_MAX





// detect the negative weight edge cycle in graph



// O(n^3)

bool floyd_warshall(vector<pair<int,pair<int,int>>>adj,int n)
{
    int **cost=new int*[n];
    for(int i=0;i<n;++i)
        cost[i]=new int[n];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cost[i][j]=INF;
    for(auto e:adj)
        cost[e.first][e.second.first]=e.second.second;
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);      
            if(cost[i][i]<0)
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
    cout<<"if you dont want to enter edge then just enter a vertex value out of bound i.e.(-ve or >=n)\n";
    while(true)
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
    }
    bool test=floyd_warshall(adj,V);
    cout<<"'Negative weight cycle Present' is proved to be "<<((test==1)?"true":"false")<<endl;
}