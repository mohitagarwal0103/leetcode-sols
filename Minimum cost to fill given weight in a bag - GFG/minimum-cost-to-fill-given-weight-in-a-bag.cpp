//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		
    int solve(int w,int arr[],int n,vector<int>&dp)
    {
        if (w==0)
        {
            return 0;
        }
        if(w<0)
        {
            return INT_MAX;
        }
        if (dp[w]!=-1)
        {
            return dp[w];
        }
        int ans=INT_MAX;
        for (int i=0;i<n;i++)
        {
            if (arr[i]!=-1)
            {
                int x=solve(w-i-1,arr,n,dp);
                if (x!=INT_MAX)
                ans=min(ans,arr[i]+x);
            }
        }
        return dp[w]=ans;
    }
	public:
	int minimumCost(int arr[], int n, int w) 
	{ 
	    vector<int>dp(w+1,-1);
	    int ans=solve(w,arr,n,dp);
	    return ans==INT_MAX ? -1 : ans;
        // Your code goes here
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends