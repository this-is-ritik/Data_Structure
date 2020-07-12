#include<bits/stdc++.h>
using namespace std;
#define MAX 10
class Graph
{
    int V;
    int adj[MAX][MAX];
    public:
        Graph(int v)
        {
            V=v;
            for(int i=0;i<V;++i)
                for(int j=0;j<V;++j)
                    adj[i][j]=INT_MAX;
        }
        void addEdge(int from,int to,int weight)
        {
            // undirected graph
            adj[from][to]=weight;
            adj[to][from]=weight;
        }
        void primMST()
        {
            int wt[V];
            int edge[V-1];
            for(int i=0;i<V;++i)
            {
            
            }
        }
        void print()
        {

        }
};
int main()
{
    Graph G1(4);
    int m,n,wt;
    while(true)
    {
        cout<<"Enter edge (from) -> (to) : ";
        cin>>m>>n;
        cout<<"Enter its weight : ";
        cin>>wt;
        if(m==-1 or n==-1)
            break;
        G1.addEdge(m,n,wt);
    }
    G1.print();
}