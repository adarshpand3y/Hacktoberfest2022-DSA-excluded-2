#include<bits/stdc++.h>
using namespace std;


vector<int> reconstructPath(int s,int e, vector<int> prev){

    vector<int> ans,pt(1,-1);
    for(int i = e; i!=0; i=prev[i]){
        ans.push_back(i);
    }

    reverse(ans.begin(),ans.end());

    if(ans[0]!=s){
        return pt;
    }

    return ans;
}

vector<int> solve(vector<int> adj[], int v,int s){
	vector<int> vis(v+1,0),prev(v+1,0);
	queue<int> q;

    q.push(s);
    vis[s] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto pp : adj[node]){
            if(!vis[pp]){
                q.push(pp);
                vis[pp] = 1;
                prev[pp] = node;
            }
        }

    }

    return prev;

}

vector<int> BFS(vector<int> adj[],int n, int s,int e){

    vector<int> prev;
    prev = solve(adj,n,s);

    return reconstructPath(s,e,prev);
}

int main(){
	int n,m;
	cout<<"Enter Number of Vertex : ";
	cin>>n;
	cout<<"Enter Number of Edges : ";
	cin>>m;

	vector<int> adj[n+1];
	for(int i = 0; i<m; i++){
		int a,b;
		cin>>a>> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int Strt,End;
	cout<<"Enter Start and End Node : ";

	vector<int> path = BFS(adj,n,Strt,End);

	if(path[0]==-1){
		cout<<"IMPOSSIBLE";
	}
	else{
		cout<<path.size()<<endl;
		for(int i = 0; i<path.size(); i++){
        	cout<<path[i]<<" ";
		}

	}
	return 0;
}