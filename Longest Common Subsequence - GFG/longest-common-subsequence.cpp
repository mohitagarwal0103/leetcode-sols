//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    // int solve(string s1,string s2,int i,int j,int x,int y,vector<vector<int>>&dp)
    // {
    //     if (i>=x || j>=y)
    //     return 0;
    //     if (dp[i][j]!=-1)
    //     return dp[i][j];
    //     if (s1[i]==s2[j])
    //     return dp[i][j]=1+solve(s1,s2,i+1,j+1,x,y,dp);
    //     else
    //     {
    //         return  dp[i][j]=max(solve(s1,s2,i+1,j,x,y,dp),solve(s1,s2,i,j+1,x,y,dp));
    //     }
    // }
    int solvetab (int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        for (int i=x-1;i>=0;i--)
        {
            for (int j=y-1;j>=0;j--){
                if (s1[i]==s2[j])
                 dp[i][j]=1+dp[i+1][j+1];
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // vector<vector<int>>dp(x,vector<int>(y,-1));
        // return solve(s1,s2,0,0,x,y,dp);
        return solvetab(x,y,s1,s2);
        // your code here
    }
};



//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends