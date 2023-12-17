//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#define mod 1000000007
class Solution
{
public:
    int countFriendsPairings(int n) 
    {
        vector<int>dp(n+1,-1);
        dp[1]=1;
        dp[2]=2;
        for (int i=3;i<=n;i++)
        {
            int s=dp[i-1];
            int d=(((long long)dp[i-2]%mod)*((long long )(i-1)%mod))%mod;
            // cout<<s<<" "<<d<<" "<<i<<endl;
            dp[i]=(s%mod+d%mod)%mod;
        }
        return dp[n];
        // code here
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends