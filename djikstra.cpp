#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX


// used to find shortest path from a starting node
// benefit from bellman ford is that 
// it can be used for large graphs
// but it requires  ->  " -ve weight edge cycle should not be in graph "


//O(n + m*logm)
// greedy approach


int* djikstra(vector<pair<int,int>>*adj,int n,int x=0)
{
    priority_queue<pair<int,int>>q;
    int *distance=new int[n];
    bool processed[n];
    memset(processed,false,sizeof(processed));
    memset(distance,INF,sizeof(distance));
    distance[x]=0;
    processed[x]=true;
    q.push(make_pair(0,x));
    while(!q.empty())
    {
        int a=q.top().second;
        q.pop();
        if(processed[a])
            continue;
        processed[a]=true;
        for(auto e:adj[a])
        {
            int b=e.first,w=e.second;
            if(distance[a]+w<distance[b])
            {
                distance[b]=distance[a]+w;
                q.push(make_pair(-distance[b],b));
            }
        }
    }
    return distance;
}





int main()
{
    int V;
    cout<<"Enter no of vertices : ";
    cin>>V;
    vector<pair<int,int>>*adj=new vector<pair<int,int>>[V];
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
        adj[i].push_back(make_pair(j,w));
    }
    int *distance=djikstra(adj,V,0);
    for(int i=0;i<V;++i)
        cout<<distance[i]<<" ";
    return 0;
}