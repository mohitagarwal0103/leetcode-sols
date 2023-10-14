//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int>&m,vector<vector<int>>&adj,stack<int>&st,int node)
	{
	    m[node]=1;
	    for (auto i:adj[node])
	    {
	        if (!m[i])
	        {
	            dfs(m,adj,st,i);
	        }
	    }
	    st.push(node);
	}
	void solve(vector<int>&m,int node,vector<int>tran[])
	{
	    m[node]=1;
	    for (auto i:tran[node])
	    {
	        if (!m[i])
	        {
	            solve(m,i,tran);
	        }
	    }
	    
	}
    int kosaraju(int v, vector<vector<int>>&adj)
    {
        stack<int>st;
        vector<int>m(v,0);
        // sort all the nodes acc to finishingg time 
        for (int i=0;i<v;i++)
        {
            if (!m[i])
            {
                dfs(m,adj,st,i);
            }
        }
        // reverse the graph 
        vector<int>tran[v];
        for (int i=0;i<v;i++)
        {
            m[i]=0;
            for (auto j:adj[i])
            {
                tran[j].push_back(i);
            }
        } 
        // unordered_map<int,bool>vis;
        // start with scc1 amd do ds 
        int cnt=0;
        while (!st.empty())
        {
            int a=st.top();
            st.pop();
            if (!m[a])
            {
                cnt++;
                solve(m,a,tran);
            }
        }
        return cnt;
        
        //code here
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends