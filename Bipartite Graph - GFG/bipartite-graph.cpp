//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int n, vector<int>adj[]){
	    vector<int>vis(n,-1);
	    for (int i=0;i<n;i++)
	    {
	        if (vis[i]==-1)
	        {
	            vis[i]=0;
	            queue<int>q;
	            q.push(i);
	            while (!q.empty())
	            {
	                int node=q.front();
	                q.pop();
	                for (auto it:adj[node])
	                {
	                    if (vis[it]==-1)
	                    {
	                        vis[it]=!vis[node];
	                        q.push(it);
	                    }
	                    else if (vis[it]==vis[node])
	                    {
	                        return false;
	                    }
	                }
	            }
	        }
	    }
	    return true;
	    // Code here
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends