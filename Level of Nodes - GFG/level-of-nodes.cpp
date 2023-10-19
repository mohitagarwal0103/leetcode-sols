//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    queue<pair<int,int>>q;
	    q.push({0,0});
	    vector<int>vis(v,0);
	    vis[0]=1;
	    if (x==0)
	    return 0;
	    while (!q.empty())
	    {
	        auto itr=q.front();
	        q.pop();
	       
	        int a=itr.first;
	        int lvl=itr.second;
	        for (auto it:adj[a])
	        {
	            if (!vis[it])
	            {
	                vis[it]=1;
	                if (it==x)
	                return lvl+1;
	                q.push({it,lvl+1});
	            }
	        }
	    }
	    return -1;
	    // code here
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends