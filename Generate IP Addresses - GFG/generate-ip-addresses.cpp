//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string> genIp(string &s) {
        vector<string>ans;
        int n=s.size();
        if (n<=3 || n>12)
        return {"-1"};
        // int maxa="255";
        for (int i=0;i<n-3 && i<3 ;i++)
        {
            string a=s.substr(0,i+1);
            if (a.size()>1 && a[0]=='0')
            break;
            if (a.size()>3)
            break;
            int ai=stoi(a);
            if (ai>255)
            break;
            for (int j=i+1;j<n-2 && j<6 ;j++)
            {
                string b=s.substr(i+1,j-i);
                if (b.size()>1 && b[0]=='0' )
                break;
                if (b.size()>3)
                break;
                int bi=stoi(b);
                if (bi>255)
                break;
                for (int k=j+1;k<n-1 && k<9 ;k++)
                {
                    // cout<<i<<" "<<j<<" "<<k<<endl;
                    string c=s.substr(j+1,k-j);
                    string d=s.substr(k+1,n-k-1);
                    if (c.size()>3 )
                    break;
                    int ci=stoi(c);
                    if (ci>255)
                    break;
                    int di=stoi(d);
                    if (di>255)
                    continue;
                    if (d.size()>3 || d.size()==0 || c.size()==0)
                    continue;
                    if (c.size()>1 && c[0]=='0')
                    break;
                    if (d.size()>1 && d[0]=='0')
                    continue;
                    
                    string res="";
                    res+=a;
                    res+='.';
                    res+=b;
                    res+='.';
                    res+=c;
                    res+='.';
                    res+=d;
                    ans.push_back(res);
                }
            }
        }
        return ans;
        // Your code here
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends