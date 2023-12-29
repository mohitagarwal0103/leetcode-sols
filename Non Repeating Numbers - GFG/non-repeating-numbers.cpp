//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int>arr) 
    {
        int x=0,n=arr.size();
        for (int i=0;i<n;i++)
        {
            x=x^arr[i];
        }
        int i=0;
        while (i<32){
            if ((1<<i)&x)
            {
                break;
            }
            i++;
        }
        int a=(1<<i);
        // cout<<a<<endl;
        int xa=0,xb=0;
        for (int j=0;j<n;j++)
        {
            if (arr[j]&(a))
            {
                xa^=arr[j];
            }
            else
            {
                xb^=arr[j];
            }
        }
        if (xa<xb)
        {
            return {xa,xb};
        }
        else
        {
            return {xb,xa};
        }
        // Code here.
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends