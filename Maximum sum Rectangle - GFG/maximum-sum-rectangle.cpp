//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int fun(vector<int>&temp,int n)
    {
        int sum=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum=sum+temp[i];
            ans=max(ans,sum);
            if(sum<0)
            sum=0;
        }
        return ans ;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>> mat) 
    {
        int res=INT_MIN;
       for(int i=0;i<r;i++)
       {
           vector<int>temp(c,0);
           for(int j=i;j<r;j++)
           {
               for(int k=0;k<c;k++)
               {
                   temp[k]=temp[k]+mat[j][k];
               }
               res=max(res,fun(temp,c));
            //   cout<<res<<" "<<j<<endl;
           }
       }
       return res ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends