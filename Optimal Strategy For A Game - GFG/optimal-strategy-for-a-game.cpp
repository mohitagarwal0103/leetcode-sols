//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int s,int e,int arr[],vector<vector<int>>&dp)
    {
        if(s>e)
        {
            return 0;
        }
        if (dp[s][e]!=-1)
        {
            return dp[s][e];
        }
        // if(dp[s][e][sum]!=-1)
        // {
        //     return dp[s][e][sum];
        // }
        return dp[s][e]=max(arr[s]+min(solve(s+1,e-1,arr,dp),solve(s+2,e,arr,dp)),arr[e]+min(solve(s+1,e-1,arr,dp),solve(s,e-2,arr,dp)));
    }
    long long maximumAmount(int arr[], int n){
        // long long int  sum=0;
        // for (int i=0;i<n;i++)
        // sum+=arr[i];
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(sum+1,-1)));
        return solve(0,n-1,arr,dp);
        // Your code here
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends