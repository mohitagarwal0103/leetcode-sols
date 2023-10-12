//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& arr) {
        int n=arr.size();
    int m=arr[0].size();
    int dr[4]={1,0,-1,0};
    int cr[4]={0,-1,0,1};
    pair<int,int>src={0,0};
    pair<int,int>dst={n-1,m-1};
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[src.first][src.second]=0;
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,src});
        while (!pq.empty())
        {
            pair<int,pair<int,int>>p=pq.front();
            pq.pop();
            int d=p.first;
            int si=p.second.first;
            int se=p.second.second;
            for (int k=0;k<4;k++)
            {
                int r=si+dr[k];
                int c=se+cr[k];
                if (r>=0 && r<n && c>=0 && c<m && dist[r][c]>max(d,abs(arr[si][se]-arr[r][c])))
                {
                    dist[r][c]=max(d,abs(arr[si][se]-arr[r][c]));
                    pq.push({dist[r][c],{r,c}});
                }
            }
        }
        return dist[dst.first][dst.second]==INT_MAX ? -1 :dist[dst.first][dst.second];
        // code here
    
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends