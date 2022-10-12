//In this code we'll be implementing Dijkstra algorithm for undirected graph using priority queue.
//Input: The first line of input should include two space separated integers(n,m), representing number of nodes and edges in the graph.
//       The next m line contains 3 integers each(u,v,w), telling that there is a edge between node u and v with weight w.
//       The next line contains a single integer (x), describing the source from where the shortest path to every other nodes needs to be calculated.
//Output:The output contains n-1 lines, each line contains 2 integers(a,b), where a is the node and b is the shortest distance from source node to a.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5;
vector<pair<ll, ll>> g[N];
vector<ll> dist(N, INT16_MAX);
vector<ll> vis(N);

void dijkstra(ll source)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        ll dis = pq.top().first;
        ll prev = pq.top().second;
        pq.pop();
        if (vis[prev])
            continue;
        vis[prev] = 1;
        for (auto child : g[prev])
        {
            if (dist[child.first] > dist[prev] + child.second)
            {
                dist[child.first] = dist[prev] + child.second;
                pq.push({dist[child.first], child.first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    ll source;

    cin >> source;

    dijkstra(source);
    for (int i = 1; i <= n; i++)
    {
        if(i!=source)
        cout <<"Node:"<<i<<" "<<"Distance: "<< dist[i] <<endl;
    }

    return 0;
}