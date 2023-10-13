//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>vis(v,0);
        vector<pair<int,int>>mst;
        pq.push({0,{0,-1}});
        int sum=0;
        while (!pq.empty())
        {
            auto itr=pq.top();
            pq.pop();
            int wt=itr.first;
            int node=itr.second.first;
            int par=itr.second.second;
            if (vis[node])
            {
                continue;
            }
            if (par!=-1)
            {
                mst.push_back({node,par});
                sum+=wt;
            }
            vis[node]=1;
            for (auto it:adj[node])
            {
                int n2=it[0];
                int w2=it[1];
                if (!vis[n2])
                {
                    pq.push({w2,{n2,node}});
                }
            }
        }
        return sum;
        // code here
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends