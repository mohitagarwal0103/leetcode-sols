//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
#define ll long long 
#define mod 1000000007
class Solution{
    public:
    long long countWays(int n, int k){
        vector<ll>single(n,0);
        vector<ll>couple(n,0);
        single[0]=k;
        couple[0]=0;
        for (int i=1;i<n;i++)
        {
            single[i]=((couple[i-1]*(k-1))%mod+(single[i-1]*(k-1))%mod)%mod;
            couple[i]=single[i-1]%mod;
        }
        return (single[n-1]%mod+couple[n-1]%mod)%mod;
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
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends