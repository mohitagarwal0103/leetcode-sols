//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int i,int j,vector<pair<int,int>>&v,vector<vector<int>>& arr,vector<vector<int>>& vis,int n,int m,int bi,int bj)
    {
        v.push_back({i-bi,j-bj});
        vis[i][j]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        for (int k=0;k<4;k++)
        {
            int r=i+row[k];
            int c=j+col[k];
            if (r>=0 && r<n && c>=0 && c<m && !vis[r][c] && arr[r][c]==1)
            {
                solve(r,c,v,arr,vis,n,m,bi,bj);
            }
        }
        return ;
    }
    int countDistinctIslands(vector<vector<int>>& arr) {
        set<vector<pair<int,int>>>st;
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (arr[i][j]==1 && !vis[i][j])
                {
                    vector<pair<int,int>>v;
                   solve(i,j,v,arr,vis,n,m,i,j);
                   st.insert(v);
                }
            }
        }
        // code here
        return st.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends