//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int solve(int i,int j,int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if (i<0 || j<0 || i>=n || j>=m)
    {
        return 0;
    }
    if (dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=arr[i][j];
    ans=max(ans,arr[i][j]+solve(i+1,j,n,m,arr,dp));
    ans=max(ans,arr[i][j]+solve(i+1,j+1,n,m,arr,dp));
    ans=max(ans,arr[i][j]+solve(i+1,j-1,n,m,arr,dp));
    return dp[i][j]=ans;
}

    int maximumPath(int n, vector<vector<int>> arr)
    {
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=0;
        for (int i=0;i<n;i++)
        {
            ans=max(ans,solve(0,i,n,n,arr,dp));
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends