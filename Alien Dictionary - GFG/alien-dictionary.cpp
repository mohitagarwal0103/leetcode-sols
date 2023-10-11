//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void solve(vector<int> adj[],stack<int>&st,unordered_map<int,bool>&m,int x)
	{
	    m[x]=true;
	    for (auto i:adj[x])
	    {
	        if (!m[i])
	        {
	            solve(adj,st,m,i);
	        }
	    }
	    st.push(x);
	    return ;
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    unordered_map<int,bool>m;
	    vector<int>ans;
	    stack<int>st;
	    for (int i=0;i<v;i++)
	    {
	       // vector<int>ans;
	        if (!m[i])
	        {
	            solve(adj,st,m,i);
	        }
	    }
	    while (!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    // code here
	}
    
    string findOrder(string dict[], int n, int k) {
        vector<int>adj[k];
        for (int i=0;i<n-1;i++)
        {
            string a=dict[i];
            string b=dict[i+1];
            int x=min(a.size(),b.size());
            for (int j=0;j<x;j++)
            {
                if (a[j]!=b[j])
                {
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
            }
        }
        vector<int>res=topoSort(k,adj);
        string ans="";
        for (int i=0;i<res.size();i++)
        {
            // cout<<res[i]<<" ";
            ans=ans+char(res[i]+'a');
        }
        // cout<<ans;
        return ans;
        //code here
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends