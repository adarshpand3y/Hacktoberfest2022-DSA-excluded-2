/*
Author :: DE-Nandan
*/
#include<bits/stdc++.h>
using namespace std;

// Creating an undirected graph as the edge is undiredcted so both way linking is done
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//main operating function on disconnected graphs to check whether it contains cycle or not 
/*
Basically what we do here is we DFS the given graph and if any node is found which is visited previously and it is not
the parent of current node whose DFS is in operation then it returns true as graph is cyclic

*/
bool DFSCycle(vector<int> adj[], int s, vector<bool> &visited, int parent)
{
     
       visited[s]=  true;
       
        for(auto x : adj[s])
        {
            if(visited[x] == false)
            {
                if(DFSCycle(adj,x,visited,s))
                return true;
            }
            else if(parent != x)
            return true;
        }
        return false;
}
// V is number of nodes
//s is source vertex
// adj is adjacency list representation of graph
bool DFSDis(vector<int> adj[], int V, int s)
{
    vector <bool> visited (V,false);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (DFSCycle(adj, i, visited, -1))
                return true;
        }
    }
    return false;
}
int main()
{
    //Graph with Cycle
    vector<int> adj[5];
    addEdge(adj,1,0);
    addEdge(adj,0,2);
    addEdge(adj,2,1);
    addEdge(adj,0,3);
    addEdge(adj,3,4);
    
    //Graph without Cycle
    // vector<int> adj[3];
    // addEdge(adj,0,1);
    // addEdge(adj,1,2);

    
   
    cout<<DFSDis(adj,5,0);
}