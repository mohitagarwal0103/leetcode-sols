//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int arr[],int n,int sum,int i,int x,vector<vector<int>>&dp)
{
    if (x==sum/2)
    {
        return 1;
    }
    if (i==n)
    {
        return 0;
    }
    if(dp[i][x]!=-1)
    return dp[i][x];
    int a=solve(arr,n,sum,i+1,x,dp);
    // x+=arr[i];
    int b=solve(arr,n,sum,i+1,x+arr[i],dp);
    return dp[i][x]=a|b;
}
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for (int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        int ans=0;
        if (sum%2!=0)
        return 0;
        int x=0;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(arr,n,sum,0,x,dp);
        
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
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends