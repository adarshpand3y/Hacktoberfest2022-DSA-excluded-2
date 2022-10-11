#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
const int inf = 1e7;
 
int main()
{
   int n,m;
   cin>>n>>m;

  vi dist(n+1,inf);
  vector<vector<pair<int,int>>> graph(n+1);

  for(int i=0;i<m;i++)
  {
    int u,v,w;
    cin>>u,v,w;

    graph[u].push_back({v,w});
    graph[v].push_back({u,w});  //Doing it for directed graph
  }

  int source;
  cin>>source;

  dist[source] = 0;

  // Creating a set
  set<pair<int,int>> s;
  s.insert({0,source});

  // Order to put inside the set is {wt, vertex}
  while (!s.empty())
  {
    /* code */
    auto x = *(s.begin());
    s.erase(x);
    for(auto it : graph[x.second])
    {
        if(dist[it.first] > dist[x.second] + it.second)
        {
            s.erase({dist[it.first], it.first});
            dist[it.first] = dist[x.second] + it.second;
            s.insert({dist[it.first], it.first});
        }
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(dist[i] < inf)
    {
      cout<<dist[i]<<" ";
    }
    else
    {
      cout<<-1<<" ";
    }
  }

  return 0;
}

