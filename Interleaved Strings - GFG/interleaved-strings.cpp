//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool solve(int i,int j,int k,string a,string b,string c,int n1,int n2,vector<vector<vector<int>>>&dp)
    {
        if (k>=(n1+n2))
        {
            return true;
        }
        if (dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        bool x=false,y=false;
        if (i<n1 && a[i]==c[k])
        {
            x=solve(i+1,j,k+1,a,b,c,n1,n2,dp);
        }
         if (j<n2 && b[j]==c[k])
        {
            y=solve(i,j+1,k+1,a,b,c,n1,n2,dp);
        }
        return dp[i][j][k]=x|y;
    }
    bool isInterleave(string a, string b, string c) 
    {
        int n1=a.size(),n2=b.size(),n3=c.size();
        vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
        return solve(0,0,0,a,b,c,n1,n2,dp);
        //Your code here
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends