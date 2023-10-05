//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>&arr) {
        queue<pair<int,int >>q;
        int cnt=0;
        int n=arr.size(),m=arr[0].size();
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(arr[i][j]==1)
                {
                    cnt++;
                }
                else if (arr[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(cnt!=0)
        {
            ans++;
            int qs=q.size();
            int f=0;
            for (int i=0;i<qs;i++)
            {
                pair<int,int >a=q.front();
                q.pop();
                int ai=a.first;
                int aj=a.second;
                if (ai-1>=0 && aj>=0 && ai-1<n && aj<m && arr[ai-1][aj]==1)
                {
                    // cout<<ai-1<<" "<<aj<<endl;
                    f=1;
                    arr[ai-1][aj]=2;
                    q.push({ai-1,aj});
                    cnt--;
                }
                if (ai>=0 && aj-1>=0 && ai<n && aj-1<m && arr[ai][aj-1]==1)
                {
                    f=1;
                    // cout<<ai<<" "<<aj-1<<endl;
                    arr[ai][aj-1]=2;
                    q.push({ai,aj-1});
                    cnt--;
                }
                if (ai+1>=0 && aj>=0 && ai+1<n && aj<m && arr[ai+1][aj]==1)
                {
                    // cout<<ai+1<<" "<<aj<<endl;
                    f=1;
                    arr[ai+1][aj]=2;
                    q.push({ai+1,aj});
                    cnt--;
                }
                if (ai>=0 && aj+1>=0 && ai<n && aj+1<m && arr[ai][aj+1]==1)
                {
                    // cout<<ai<<" "<<aj+1<<endl;
                    f=1;
                    arr[ai][aj+1]=2;
                    q.push({ai,aj+1});
                    cnt--;
                }
            }
            if (!f)
            break;
        }
        if (cnt==0)
        {
            return ans;
        }
        else
        {
            return -1;
        }
        // Code here
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends