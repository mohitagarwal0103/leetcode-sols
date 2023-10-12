//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& arr) {
        
        vector<pair<int,int>>adj[n];
        for (int i=0;i<arr.size();i++)
        {
            adj[arr[i][0]].push_back({arr[i][1],arr[i][2]});
            adj[arr[i][1]].push_back({arr[i][0],arr[i][2]});
        }
        vector<int>ways(n,0);
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        int mod=(int)(1e9+7);
        // {dist,node}
        while (!pq.empty())
        {
            auto itr=pq.top();
            pq.pop();
            int d=itr.first;
            int node=itr.second;
            for (auto it:adj[node])
            {
                int n2=it.first;
                int w=it.second;
                // cout<<n2<<" "<<w<<endl;
                if (dist[n2]>w+d)
                {
                    dist[n2]=(w+d)%mod;
                    pq.push({dist[n2],n2});
                    ways[n2]=ways[node];
                }
                else if (dist[n2]==w+d)
                {
                    ways[n2]=(ways[n2]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends