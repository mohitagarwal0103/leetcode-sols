//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int mod=INT_MAX;
  public:
    int isPossible(int n, int arr[]) {
        long long int sum=0;
        for (int i=0;i<n;i++)
        {
            while (arr[i])
            {
                sum+=(arr[i]%10);
                arr[i]/=10;
            }
        }
        return sum%3==0;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends