//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// map<pair<string,int>,int>mp;
// int ispal(string s)
// {
//     string a=s;
//     reverse(s.begin(),s.end());
//     return a==s;
// }
class Solution{
  public:
    // int solve(int i,string s,string tmp,int n)
    // {
    //     if (i==n)
    //     {
    //         if (ispal(tmp))
    //         {
    //             return abs(s.size()-tmp.size());
    //         }
    //         else
    //         {
    //             return INT_MAX;
    //         }
    //     }
    //     if (mp.count({tmp,i}))
    //     {
    //         return mp[{tmp,i}];
    //     }
    //     int nt=solve(i+1,s,tmp,n);
    //     tmp+=s[i];
    //     int t=solve(i+1,s,tmp,n);
    //     tmp.pop_back();
    //     return mp[{tmp,i}]=min(nt,t);
    // }
    
    int solvetab (int x, int y, string s1, string s2)
    {
        vector<int>curr(y+1,0);
        vector<int>next(y+1,0);
        for (int i=x-1;i>=0;i--)
        {
            for (int j=y-1;j>=0;j--){
                int ans=0;
                if (s1[i]==s2[j])
                 ans=1+next[j+1];
                else
                {
                    ans=max(next[j],curr[j+1]);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int longestPalinSubseq(string a) {
        string b=a;
        reverse(a.begin(),a.end());
        int n=a.size();
        return solvetab(n,n,a,b);
        //code here
    }
    int minimumNumberOfDeletions(string s) { 
        return s.size()-longestPalinSubseq(s);
        // mp.clear();
        // return solve(0,s,"",s.size());
        // code here
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends