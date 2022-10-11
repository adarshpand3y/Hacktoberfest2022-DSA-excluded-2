// author: CoderGhost37

#include <bits/stdc++.h>
using namespace std;

vector< vector<pair<int,int>> > G;
vector<int> vis;

// returns the minimum spanning tree
int prims() {
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;   // min heap (on the basis of weight, i.e., it will sort on the basis of weight) containing a vertice with a key value(weight)
    pq.push({0,1});                                                                      // here 1st value represent the weight and 2nd value can be any of the vertex present in graph G
    int mst_sum=0;
    while(!pq.empty()) {
        int u = pq.top().second, curr_weight = pq.top().first;
        pq.pop();
        if(vis[u])
            continue;
        mst_sum += curr_weight;
        vis[u] = 1;
        for(auto v: G[u]) { 
            if(!vis[v.first])
                pq.push({v.second, v.first});
        }
    }
    return mst_sum;
}

int main()
{
    int n, m;    
    cin>>n>>m;

    // adjacency list for weighted graph
    G.resize(n);   // G[i] will contain all the nodes which are adjacent to i

    // input format
    for(int i=0; i<m ; i++){
        int u, v, w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    vis.resize(n);                        // to resize the vector vis intoduced globally
        // vis[i]=0 => i is not visited
        // vis[i]=1 => i is visited
    cout<<prims();

    return 0;
}
