//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        vector<int>v(26,0);
        v['I'-'A']=1;
        v['V'-'A']=5,v['X'-'A']=10,v['L'-'A']=50,
        v['C'-'A']=100 , v['D'-'A']=500,v['M'-'A']=1000;
        int i=0,n=s.size(),ans=0;
        while (i<n-1)
        {
            if (v[s[i]-'A']>=v[s[i+1]-'A'])
                ans+=(v[s[i]-'A']);
            else
            {
                ans+=(v[s[i+1]-'A']-v[s[i]-'A']);
                i++;
            }
            i++;
        }
        if (i<n)
        {
            ans+=v[s[i]-'A'];
        }
        return ans;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends