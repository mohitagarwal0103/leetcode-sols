//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&arr){
	    int n=arr.size();
	   // vector<vector<int>>ans(n,vector<int>(n,INT_MAX));
	    for (int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if (arr[i][j]==-1)
	            {
	                arr[i][j]=1e9;
	            }
	            if (i==j)
	            {
	                arr[i][j]=0;
	            }
	        }
	    }
	    for (int k=0;k<n;k++)
	    {
	        for (int i=0;i<n;i++)
	        {
	            for (int j=0;j<n;j++)
	            {
	                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
	            }
	        }
	    }
	    for (int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if (arr[i][j]==1e9)
	            {
	                arr[i][j]=-1;
	            }
	            if (i==j)
	            {
	                arr[i][j]=0;
	            }
	        }
	    }
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends