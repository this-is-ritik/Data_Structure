#include<bits/stdc++.h>
using namespace std;



class graph
{
    int V,E;
    vector<pair<int,pair<int,int>>edges;
    public:
        graph(int V,int E)
        {
            this->V=V;
            this->E=E;
        }
        void addEdge(int u,int v,int w)
        {
            edges.push_back({w,{u,v}});
        }

        int kruskal()
        {
            
        }
};