//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer=0;
  public:
  void dfs(int node,int par,vector<int>&vis,vector<int>adj[],int tin[],int low[],vector<int>&mark)
    {
        vis[node]=1;
        low[node]=tin[node]=timer;
        timer++;
        int child=0;
        for (auto it:adj[node])
        {
            if (it==par)
            continue;
            if(!vis[it])
            {
                dfs(it,node,vis,adj,tin,low,mark);
                low[node]=min(low[node],low[it]);
                if (low[it]>=tin[node] && par!=-1)
                {
                    mark[node]=1;
                }
                child++;
            }
            else {
                low[node]=min(low[node],tin[it]);
            }
        }
        if (child>1 && par==-1)
        {
            mark[node]=1;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<int>mark(n,0);
        dfs(0,-1,vis,adj,tin,low,mark);
        vector<int>ans;
        for (int i=0;i<n;i++)
        {
            if (mark[i]==1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size()==0)
        return {-1};
        return ans;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends