//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int arr[])
    {
        vector<int>dp(n,1);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (abs(arr[i]-arr[j])==1)
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
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
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends