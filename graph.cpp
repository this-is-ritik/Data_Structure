#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class Graph
{
    int V;
    int E;
    vector<int>adj[MAX];
    public:
        Graph(int V)
        {
            this->V=V;
            E=0;
        }
        // directed graph
        void addEdge(int from , int to)
        {
            if(from>V or to>V)
                return;
            adj[from].push_back(to);
            E++;
        }

        void bfs(int s)
        {
            // for bfs use queue
            bool visited[V]={false};
            queue<int>q;
            q.emplace(s);
            while(!q.empty())
            {
                int temp=q.front();
                q.pop();
                if(!visited[temp])
                {
                    visited[temp]=true;
                    cout<<temp<<" ";
                }
                for(int i=0;i<adj[temp].size();++i)
                {
                    if(!visited[adj[temp][i]])
                        q.emplace(adj[temp][i]);
                }
            }
            cout<<endl;
        }
        void dfs(int s)
        {
            // for dfs use stack
            bool visited[V]={false};
            stack<int>stk;
            stk.push(s);
            while(!stk.empty())
            {
                int temp=stk.top();
                stk.pop();
                if(!visited[temp])
                {
                    visited[temp]=true;
                    cout<<temp<<" ";
                }
                for(int i=0;i<adj[temp].size();++i)
                {
                    if(!visited[adj[temp][i]])
                    {
                        stk.push(adj[temp][i]);
                    }
                }
            }
        }
        void topological_sort()
        {
            // kahn's algorithm
            vector<int>ind(V,0);
            for(int i=0;i<V;++i)
            {
                for(int j=0;j<adj[i].size();++j)
                {
                    ind[adj[i][j]]++;
                }
            }
            queue<int>q;
            for(int i=0;i<V;++i)
                if(ind[i]==0)
                    q.push(i);
            int cnt=0;
            vector<int>top_order;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                top_order.push_back(u);
                for(int i=0;i<adj[u].size();++i)
                {
                    if(--ind[adj[u][i]]==0)
                        q.push(adj[u][i]);
                }
                cnt++;
            }
            if(cnt!=V)
            {
                cout<<"there exist a cycle in the graph!!!\n";
                return;
            }
            for(int i=0;i<top_order.size();++i)
                cout<<top_order[i]<<" ";
            cout<<endl;
        }
        void Bellman_Ford(int u)
        {
            int dist[V]={INT_MAX};
            dist[u]=0;
            for(int i=0;i<V;++i)
            {
                // relax edges
                
            }
        }
        void printGraph()
        {
            for(int i=0;i<V;++i)
            {
                if(adj[i].size()==0)
                    continue;
                cout<<i;
                for(int j=0;j<adj[i].size();++j)
                    cout<<" -> "<<adj[i][j];
                cout<<endl;
            }
        }
};
int main()
{
    int v;
    cout<<"Enter no of vertices : ";
    cin>>v;
    Graph G1(v);
    int m,n;
    while(true)
    {
        cout<<"Enter edge (from) -> (to) : ";
        cin>>m>>n;
        if(m>v or m<0 or n<0 or n>0)
            break;
        G1.addEdge(m,n);
    }
    G1.bfs(0);
    cout<<endl;
    G1.dfs(0);
    cout<<endl;
    G1.topological_sort();
    cout<<endl;
    G1.printGraph();
}



// no of mst from a G=(V,E)
/*

|E| C (|V|-1)

*/