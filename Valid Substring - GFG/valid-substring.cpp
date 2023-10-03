//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        int l=0,r=0,m=0;
        for(int i=0;i<s.size();i++)
        {
            if (s[i]=='(')
            l++;
            else
            r++;
            if (l==r)
            {
                m=max(m,2*r);
            }
            else if (r>l)
            {
                l=0;
                r=0;
            }
            
        }
        l=0;
        r=0;
        for (int i=s.size()-1;i>=0;i--)
        {
            if (s[i]==')')
            l++;
            else
            r++;
            if (l==r)
            {
                m=max(m,2*r);
            }
            else if (r>l)
            {
                l=0;
                r=0;
            }
        }
        return m;
        // code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends