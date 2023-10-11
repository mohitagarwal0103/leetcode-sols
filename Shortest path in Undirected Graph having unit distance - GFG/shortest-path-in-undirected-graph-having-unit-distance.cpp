//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& ed, int n,int m, int src){
        vector<int>dist(n,INT_MAX);
        vector<int>adj[n];
        for (int i=0;i<m;i++)
        {
            adj[ed[i][0]].push_back(ed[i][1]);
            adj[ed[i][1]].push_back(ed[i][0]);
        }
        dist[src]=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        while (!q.empty())
        {
            pair<int,int>a=q.front();
            q.pop();
            int f=a.first;
            int d=a.second;
            for (auto it:adj[f])
            {
                if(dist[it]>d+1)
                {
                    if (dist[it]==INT_MAX)
                    {
                        q.push({it,d+1});
                        dist[it]=d+1;
                    }
                    
                    // q.push({it,dist[it]});
                }
                
            }
        }
        for (int i=0;i<n;i++)
        {
            if(dist[i]==INT_MAX)
            {
                dist[i]=-1;
            }
        }
        return dist;
        // code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends