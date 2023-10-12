//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
//   stops ,node, dist 
    int CheapestFLight(int n, vector<vector<int>>& fl, int src, int dst, int k)  {
        vector<vector<int>>adj[n];
        for (int i=0;i<fl.size();i++)
        {
            adj[fl[i][0]].push_back({fl[i][1],fl[i][2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});
        while (!q.empty())
        {
            pair<int,pair<int,int>>p=q.front();
            q.pop();
            int stops=p.first;
            int node =p.second.first;
            int d=p.second.second;
            if (stops>k)
            continue;
            for(auto it:adj[node])
            {
                int n2=it[0];
                int w=it[1];
                if (dist[n2]>d+w)
                {
                    if(stops<=k)
                    {
                        // cout<<dist[node] <<" "<<node <<" "<<d<<endl;
                        dist[n2]=d+w;
                        q.push({stops+1,{n2,dist[n2]}});
                    }
                }
            }
        }
        return dist[dst]==INT_MAX? -1 :dist[dst] ;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends