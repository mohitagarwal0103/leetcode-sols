//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int dx[8]={-1,-2,-2,-1,1,2,2,1};
    int dy[8]={-2,-1,1,2,-2,-1,1,2};
    bool issafe(int i,int j,int n)
    {
        if (i<0 || i>=n || j<0 || j>=n )
        {
            return false;
        }
        return true;
    }
	int minStepToReachTarget(vector<int>&ip,vector<int>&tp,int n)
	{
	    int ix=ip[0]-1;
	    int iy=ip[1]-1;
	    int tx=tp[0]-1,ty=tp[1]-1;
	    vector<vector<int>>vis(n,vector<int>(n,0));
	    queue<pair<int,int>>q;
	    q.push({ix,iy});
	    q.push({-1,-1});
	    vis[ix][iy]=1;
	    int cnt=0;
	    while (!q.empty())
	    {
	        pair<int,int>p=q.front();
	        q.pop();
	        int cx=p.first;
	        int cy=p.second;
	        if (cx==-1 && cy==-1)
	        {
	            cnt++;
	            if (!q.empty())
	            q.push({-1,-1});
	            continue;
	        }
	        if (cx==tx && cy==ty)
	        return cnt;
	    
	        for (int k=0;k<8;k++)
	        {
	            int nx=cx+dx[k];
	            int ny=cy+dy[k];
	            if (issafe(nx,ny,n) && !vis[nx][ny])
	            {
	                vis[nx][ny]=1;
	                q.push({nx,ny});
	            }
	        }
	    }
	    return -1;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends