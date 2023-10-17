//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
void solve(int i,int j,vector<int>&vis,vector<vector<int>>&ans,vector<int>adj[])
{
    ans[i][j]=1;
    // cout<<i<<" "<<j<<endl;
    vis[j]=1;
    for (auto it:adj[j])
    {
        if (!vis[it])
        {
            solve(i,it,vis,ans,adj);
        }
    }
    return ;
}
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> arr)
    {
        vector<int>adj[n];
        vector<vector<int>>ans(n,vector<int>(n,0));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (arr[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        // for (int i=0;i<n;i++)
        // {
        //     for (auto it:adj[i])
        //     {
        //         // cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        for (int i=0;i<n;i++)
        {
            vector<int>vis(n,0);
            solve(i,i,vis,ans,adj);
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends