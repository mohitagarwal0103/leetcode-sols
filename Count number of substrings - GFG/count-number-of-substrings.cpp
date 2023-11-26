//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    int solve(string s,int k)
    {
        if (k==0)
        return 0;
        int n=s.size();
        int st=0,e=0;
        int ans=0,dis=0;
        vector<int>v(26,0);
        while (e<n)
        {
            if (v[s[e]-'a']==0)
            {
                dis++;
                v[s[e]-'a']++;
            }
            else
            {
                v[s[e]-'a']++;
            }
            while (dis>k && st<e)
            {
                ans+=(e-st);
                if (v[s[st]-'a']==1)
                {
                    v[s[st]-'a']--;
                    dis--;
                }
                else
                {
                    v[s[st]-'a']--;
                }
                st++;
            }
            e++;
        }
        while (st<e)
        {
            ans+=(e-st);
            st++;
        }
        return ans;
    }
  public:
    long long int substrCount (string s, int k) {
        return solve(s,k)-solve(s,k-1);
        // -solve(s,k-1)
    	//code here.
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends