//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int v,int p, vector<pair<int, int> >& pre) {
	    vector<int>adj[v];
	    for (int i=0;i<p;i++)
	    {
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    
	   vector<int>in(v,0);
	   for (int i=0;i<v;i++)
	   {
	       for (auto j:adj[i])
	       {
	           in[j]++;
	       }
	   }
	   vector<int>ans;
	   queue<int>q;
	   for(int i=0;i<v;i++)
	   {
	       if (in[i]==0)
	       {
	           q.push(i);
	       }
	   }
	   int cnt=0;
	   while (!q.empty())
	   {
	       int f=q.front();
	       q.pop();
	       cnt++;
	       for (auto i:adj[f])
	       {
	           in[i]--;
	           if (in[i]==0)
	           {
	               q.push(i);
	           }
	       }
	   }
	   return (cnt==v);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends