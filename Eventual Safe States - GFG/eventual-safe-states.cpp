//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool solve(int i ,vector<int>&vis,vector<int>&path,vector<int>adj[],vector<int>&s)
    {
        vis[i]=1;
        path[i]=1;
        bool f=true;
        for (auto it:adj[i])
        {
            if (!vis[it])
            {
                bool a=solve(it,vis,path,adj,s);
                f=f&a;
            }
            else if (path[it])
            {
                return false;
            }
            if (f==false)
            {
                return false;
            }
        }
        path[i]=0;
        if (f)
        {
            s[i]=1;
        }
        // else
        // {
        //     s[i]=0;
        // }
        return f;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int>vis(n,0);
        vector<int>path(n,0);
        vector<int>s(n,0);
        vector<int>ans;
        for (int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                bool tmp=solve(i,vis,path,adj,s);
            }
        }
        for (int i=0;i<n;i++)
        {
            if(s[i]==1)
            {
                ans.push_back(i);
            }
        }
        return ans;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends