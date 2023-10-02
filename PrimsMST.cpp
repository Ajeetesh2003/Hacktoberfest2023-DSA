#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj List
    unordered_map<int, list<pair<int,int> > > adj;       //u->(v,weight)
    for(int i=0; i<g.size(); ++i){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0; i<=n; ++i){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    //start algo
    key[1] = 0;                     // min dist tracker
    parent[1] = -1;

    for(int i=1; i<n; ++i){

        int mini = INT_MAX;
        int u;
        //find the min vali node
        for(int v = 1; v<=n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        //mark min node as true;
        mst[u] = true;

        //check its adjacency node
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    //running from 2 as parent of 1 is marked as -1
    for(int i=2; i<=n; ++i){
      result.push_back({{parent[i], i}, key[i]});
    }

    return result;

}
