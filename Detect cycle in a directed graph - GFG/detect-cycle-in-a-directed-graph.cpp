//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // bool solve(int i ,vector<int>&vis,vector<int>&path,vector<int>adj[])
    // {
    //     vis[i]=1;
    //     path[i]=1;
    //     for (auto it:adj[i])
    //     {
    //         if (!vis[it])
    //         {
    //             bool a=solve(it,vis,path,adj);
    //             if (a)
    //             return true;
    //         }
    //         else if (path[it])
    //         {
    //             return true;
    //         }
    //     }
    //     path[i]=0;
    //     return false;
    // }
    bool isCyclic(int n, vector<int> adj[]) {
        // vector<int>vis(n,0);
        // vector<int>path(n,0);
        // for (int i=0;i<n;i++)
        // {
        //     if(!vis[i])
        //     {
        //         bool tmp=solve(i,vis,path,adj);
        //         if (tmp)
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;
        vector<int>in(n,0);
        queue<int>q;
        for (int i=0;i<n;i++)
        {
            for (auto it:adj[i])
            {
                in[it]++;
            }
        }
        int cnt=0;
        for (int i=0;i<n;i++)
        {
            if (in[i]==0)
            {
                cnt++;
                q.push(i);
            }
        }
        while (!q.empty())
        {   
            int node=q.front();
            q.pop();
            for (auto it:adj[node])
            {
                in[it]--;
                if (in[it]==0)
                {
                    cnt++;
                    q.push(it);
                }
            }
        }
        return cnt!=n;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends