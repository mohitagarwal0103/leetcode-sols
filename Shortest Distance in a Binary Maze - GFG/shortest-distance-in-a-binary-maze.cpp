//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &arr, pair<int, int> src,pair<int, int> dst) {
    int n=arr.size();
    int m=arr[0].size();
    int dr[4]={1,0,-1,0};
    int cr[4]={0,-1,0,1};
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
                if (r>=0 && r<n && c>=0 && c<m && arr[r][c]==1 && dist[r][c]>d+1)
                {
                    dist[r][c]=d+1;
                    pq.push({dist[r][c],{r,c}});
                }
            }
        }
        return dist[dst.first][dst.second]==INT_MAX ? -1 :dist[dst.first][dst.second];
        // code here
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends