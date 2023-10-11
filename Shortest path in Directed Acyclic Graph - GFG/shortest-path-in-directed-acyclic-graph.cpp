//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void solve(int i,stack<int>&st,vector<int>&vis,vector<int>adj[])
	{
	    vis[i]=1;
	    for (auto it:adj[i])
	    {
	        if(!vis[it])
	        {
	            solve(it,st,vis,adj);
	        }
	    }
	    st.push(i);
	    return ;
	}
	stack<int> topoSort(int n, vector<int> adj[]) 
	{
	    stack<int>st;
	    vector<int>ans;
	    vector<int>vis(n,0);
	    for (int i=0;i<n;i++)
	    {
	        if (!vis[i])
	        {
	            solve(i,st,vis,adj);
	        }
	    }
	    return st;
	}
     vector<int> shortestPath(int n,int m, vector<vector<int>>& ed){
        vector<pair<int,int>>adj[n];
        vector<int>adj1[n];
        for (int i=0;i<m;i++)
        {
            adj1[ed[i][0]].push_back(ed[i][1]);
            adj[ed[i][0]].push_back({ed[i][1],ed[i][2]});
        }
        stack<int>st=topoSort(n,adj1);
        vector<int>dist(n,INT_MAX);
        int src=0;
        // you can take whatever source you want 
        dist[src]=0;
        while (!st.empty())
        {
            int f=st.top();
            st.pop();
            // cout<<f<<endl;
            if (dist[f]==INT_MAX)
            { 
                continue;
            }
            for (auto it :adj[f])
            {
                int node=it.first;
                int w=it.second;
                // cout<<node<<" "<<f<<endl;
                if (dist[f]+w<dist[node])
                {
                    dist[node]=dist[f]+w;
                }
            }
        }
        for (int i=0;i<n;i++)
        {
            if (dist[i]==INT_MAX)
            {
                dist[i]=-1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends