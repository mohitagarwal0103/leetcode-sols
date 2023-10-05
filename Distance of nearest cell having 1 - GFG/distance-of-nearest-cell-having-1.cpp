//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>arr)
	{
        queue<pair<int,int >>q;
        int cnt=0;
        int n=arr.size(),m=arr[0].size();
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(arr[i][j]==0)
                {
                    cnt++;
                }
                else if (arr[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>ans(n,vector<int>(m,0));
        while(cnt!=0)
        {
            int qs=q.size();
            int f=0;
            for (int i=0;i<qs;i++)
            {
                pair<int,int >a=q.front();
                q.pop();
                int ai=a.first;
                int aj=a.second;
                if (ai-1>=0 && aj>=0 && ai-1<n && aj<m && arr[ai-1][aj]==0)
                {
                    // cout<<ai-1<<" "<<aj<<endl;
                    f=1;
                    arr[ai-1][aj]=1;
                    q.push({ai-1,aj});
                    cnt--;
                    ans[ai-1][aj]=1+ans[ai][aj];
                }
                if (ai>=0 && aj-1>=0 && ai<n && aj-1<m && arr[ai][aj-1]==0)
                {
                    f=1;
                    // cout<<ai<<" "<<aj-1<<endl;
                    arr[ai][aj-1]=1;
                    q.push({ai,aj-1});
                    cnt--;
                    ans[ai][aj-1]=1+ans[ai][aj];
                }
                if (ai+1>=0 && aj>=0 && ai+1<n && aj<m && arr[ai+1][aj]==0)
                {
                    // cout<<ai+1<<" "<<aj<<endl;
                    f=1;
                    arr[ai+1][aj]=1;
                    q.push({ai+1,aj});
                    cnt--;
                    ans[ai+1][aj]=1+ans[ai][aj];
                }
                if (ai>=0 && aj+1>=0 && ai<n && aj+1<m && arr[ai][aj+1]==0)
                {
                    // cout<<ai<<" "<<aj+1<<endl;
                    f=1;
                    arr[ai][aj+1]=1;
                    q.push({ai,aj+1});
                    cnt--;
                    ans[ai][aj+1]=1+ans[ai][aj];
                }
            }
            if (!f)
            break;
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends