//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // queue<pair<int,int>>q;
        // // { count of mulipications,node}
        // q.push({0,start});
        // int mod=100000;
        // unordered_map<int,int>vis;
        // while (!q.empty())
        // {
        //     auto itr=q.front();
        //     q.pop();
        //     int node=itr.second;
        //     int count=itr.first;
        //     if (node==end)
        //     {
        //         return count ;
        //     }
        //     for (int i=0;i<arr.size();i++)
        //     {
        //         int a=(node*arr[i])%mod;
        //         if (!vis.count(a))
        //         {
        //             vis[a]++;
        //             if (a==end)
        //             {
        //                 return count+1;
        //             }
        //             q.push({count+1,a});
        //         }
        //     }
        // }
        // return -1;
        
        
        queue<pair<int,int>>q;
        // { count of mulipications,node}
        q.push({0,start});
        int mod=100000;
        vector<int>dist(100000,INT_MAX);
        dist[start]=0;
        if (start==end)
        return 0;
        while (!q.empty())
        {
            auto itr=q.front();
            q.pop();
            int node=itr.second;
            int count=itr.first;
            for (int i=0;i<arr.size();i++)
            {
                int a=(node*arr[i])%mod;
                if (dist[a]>count+1)
                {
                    if (a==end)
                    {
                        return count+1;
                    }
                    dist[a]=count+1;
                    q.push({count+1,a});
                }
            }
        }
        return -1;
        // code here
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends