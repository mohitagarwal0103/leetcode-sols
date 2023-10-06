//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char,int>m;
        for (int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        priority_queue<int>q;
        for (auto i:m)
        {
            q.push(i.second);
        }
        int cnt=0;
        while (!q.empty() && cnt<k)
        {
            int a=q.top();
            q.pop();
            a--;
            q.push(a);
            cnt++;
        }
        int sum=0;
        while (!q.empty())
        {
            sum+=(q.top())*(q.top());
            q.pop();
        }
        return sum;
        // sort(s.begin(),s.end());
        // int n=s.length();
        // vector<int>v;
        // int count=1;
        // for (int i=0;i<n-1;i++)
        // {
        //     if (s[i]==s[i+1])
        //     {
        //         count++;
        //     }
        //     else
        //     {
        //         v.push_back(count);
        //         count=1;
        //     }
        // }
        // v.push_back(count);
        // sort(v.begin(),v.end());
        // int sum=0;
        // int l=v.size();
        // int j=1;
        // while (k!=0)
        // {
        //     if (v[l-j]>=k && l>=j)
        //     {
        //         v[l-j]-=k;
        //         k=0;
        //     }
        //     else
        //     {
        //         k-=v[l-j];
        //         v[l-j]=0;
        //         j++;
        //     }
        //     if (j>l)
        //     {
        //         return 1;
        //     }
        // }
        
        // for (int i=0;i<l;i++)
        // {
        //     sum+=(v[i]*v[i]);
        // }
        // return sum;
        // code here
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends