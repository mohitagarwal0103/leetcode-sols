//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:





int solve(int i,int k,vector<int>arr,int n,int nk,vector<vector<int>>&dp)
{
    if (i>=n)
    {
        if (k==nk)
        {
            return 0;
        }
        return k*k;
    }
    int pk=k;
    if (dp[i][k]!=-1)
    {
        return dp[i][k];
    }
    if(i==n-1)
    {
        if (k==nk)
        {
            return dp[i][pk]=0;
        }
        else
        {
            if (k>=(arr[i]+1))
            {
                return dp[i][pk]=0;
            }
            else
            {
                return dp[i][pk]=k*k;
            }
        }
    }
    // cout<<i<<" "<<k<<endl;
    if(k>arr[i])
    {
        if (k==nk)
        {
            k-=arr[i];
        }
        else
        {
            k-=(arr[i]+1);
        }
        return dp[i][pk]=min(k*k+solve(i+1,nk,arr,n,nk,dp),solve(i+1,k,arr,n,nk,dp));
    }
    else if (k==arr[i])
    {
        if (k==nk)
        {
            k-=arr[i];
            return dp[i][pk]=solve(i+1,nk,arr,n,nk,dp);
        }
        else
        {
            return dp[i][pk]=min(k*k+(nk-arr[i])*(nk-arr[i])+solve(i+1,nk,arr,n,nk,dp),k*k+solve(i+1,nk-arr[i],arr,n,nk,dp));
        }
    }
    else
    {
        return dp[i][pk]=min(k*k+(nk-arr[i])*(nk-arr[i])+solve(i+1,nk,arr,n,nk,dp),k*k+solve(i+1,nk-arr[i],arr,n,nk,dp));
    }
}
    int solveWordWrap(vector<int>arr, int k) 
    { 
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(0,k,arr,arr.size(),k,dp);
        // Code here
    } 

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends