//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int i ,string s,vector<string >&ans,string tmp)
	{
	    if (i>=s.size())
	    {
	        if (tmp.size())
	        ans.push_back(tmp);
	        return ;
	    }
	    solve(i+1,s,ans,tmp);
	    tmp+=s[i];
	    solve(i+1,s,ans,tmp);
	}
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    solve(0,s,ans,"");
		    sort(ans.begin(),ans.end());
		    return ans;
		    // Code here
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends