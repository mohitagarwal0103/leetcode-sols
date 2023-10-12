//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& ed) {
        vector<vector<int>>adj[n+1];
        for (int i=0;i<m;i++)
        {
            adj[ed[i][0]].push_back({ed[i][1],ed[i][2]});
            adj[ed[i][1]].push_back({ed[i][0],ed[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        vector<int>par(n+1);
        for (int i=1;i<n+1;i++)
        {
            par[i]=i;
        }
        int s=1;
        dist[s]=0;
        pq.push({0,s});
        while (!pq.empty())
        {
            pair<int,int>p=pq.top();
            pq.pop();
            int d=p.first;
            int node =p.second;
            for (auto it:adj[node])
            {
                int n2=it[0];
                int w=it[1];
                if (dist[n2]>dist[node]+w)
                {
                    dist[n2]=dist[node]+w;
                    pq.push({dist[n2],n2});
                    par[n2]=node;
                }
            }
        }
        vector<int>ans;
        int node=n;
        if (par[node]==node)
        {
            return {-1};
        }
        while (par[node]!=node)
        {
            ans.push_back(node);
            node=par[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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