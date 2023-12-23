//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long getCount(int n)
	{
	    vector<vector<long long int >>dp(n+1,vector<long long int>(10,0));
	    vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
	    for (int i=0;i<=9;i++)
	    {
	        dp[1][i]=1;
	    }
	    for (int i=2;i<=n;i++)
	    {
	        for (int j=0;j<4;j++)
	        {
	            for (int k=0;k<3;k++)
	            {
	                int a=arr[j][k];
	                if (a==-1)
	                {
	                    continue;
	                }
	                int dx[4]={-1,0,1,0};
	                int dy[4]={0,1,0,-1};
	                for (int q=0;q<4;q++)
	                {
	                    int nx=j+dx[q];
	                    int ny=k+dy[q];
	                    if (nx>=0 && ny>=0 && nx<4 && ny<3)
	                    {
	                        if (arr[nx][ny]==-1)
	                        continue;
	                        dp[i][a]+=dp[i-1][arr[nx][ny]];
	                    }
	                }
	                dp[i][a]+=dp[i-1][a];
	            }
	        }
	    }
	    long long ans=0;
	    for (int i=0;i<10;i++)
	    {
	        ans+=dp[n][i];
	    }
	    return ans;
	}









};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends