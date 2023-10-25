//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int n,int w,int val[],int wt[],vector<int>&dp)
{
    if (w==0)
    return 0;
    if (dp[w]!=-1)
    return dp[w];
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (wt[i]<=w)
        {
            int t=val[i]+solve(n,w-wt[i],val,wt,dp);
            // int nt=solve()
            ans=max(ans,t);
        }
    }
    return dp[w]=ans;
}

    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<int>dp(w+1,-1);
        return solve(n,w,val,wt,dp);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends