//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
// unordered_map<string,bool>mp;
// vector<int>dp(1001,-1);
// long long int solve(int n,int th,int f,int te)
// {
//     if (n==0)
//     {
//         string tmp="";
//         tmp+=th;
//         tmp+=f;
//         tmp+=te;
//         if (!mp.count(tmp))
//         {
//             mp[tmp]=true;
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     if (n<0)
//     {
//         return 0;
//     }
// 	if (dp[n]!=-1)
// 	{
// 	    return dp[n];
// 	}
// 	long long int ans=0;
// 	ans+=solve(n-3,th+1,f,te);
// 	ans+=solve(n-5,th,f+1,te);
// 	ans+=solve(n-10,th,f,te+1);
// 	return dp[n]=ans;
// }
long long int count(long long int n)
{
    long long int arr[n+1];
    memset(arr,0,sizeof(arr));
    arr[0]=1;
    for (int i=0;i<=n;i++)
    {
        if (i>=3)
        arr[i]+=arr[i-3];
    }
    for (int i=0;i<=n;i++)
    {
        if (i>=5)
        arr[i]+=arr[i-5];
    }
    for (int i=0;i<=n;i++)
    {
        if (i>=10)
        arr[i]+=arr[i-10];
    }
    return arr[n];
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends