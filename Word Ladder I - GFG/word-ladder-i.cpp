//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string sw, string tw, vector<string>& wl) {
        unordered_set<string>st(wl.begin(),wl.end());
        // for (int i=0;i<wl.size();i++)
        // {
        //     st.insert(wl[i]);
        // }
        queue<pair<string ,int>>q;
        q.push({sw,1});
        st.erase(sw);
        while (!q.empty())
        {
            string a=q.front().first;
            int d=q.front().second;
            q.pop();
            if (a==tw)
            {
                return d;
            }
            for (int k=0;k<a.size();k++)
            {
                for (int h=0;h<26;h++)
                {
                    string tmp=a;
                    tmp[k]='a'+h;
                    if (st.find(tmp)!=st.end())
                    {
                        q.push({tmp,d+1});
                        st.erase(tmp);
                    }
                }
            }
        }
        return 0;
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
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends