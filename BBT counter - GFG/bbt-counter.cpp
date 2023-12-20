//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
// User function Template for C++
class Solution {
  public:
    long long int countBT(int h) { 
        vector<long long int >dp(h+1,0);
        dp[1]=1;
        dp[2]=3;
        for (int i=3;i<=h;i++)
        {
            dp[i]=((dp[i-1]*dp[i-1])%mod+((long long int)2*(dp[i-1]*dp[i-2]))%mod)%mod;
        }
        return dp[h]%mod;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends