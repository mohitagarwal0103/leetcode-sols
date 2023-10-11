//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string sw, string tw, vector<string>& wl) {
        unordered_set<string>st(wl.begin(),wl.end());
        queue<vector<string>>q;
        q.push({sw});
        int lvl=0;
        vector<string>usedonlevel;
        usedonlevel.push_back(sw);
        vector<vector<string>>ans;
        while (!q.empty())
        {
            vector<string>tmp=q.front();
            q.pop();
            if (tmp.size()>lvl)
            {
                lvl++;
                for (auto it:usedonlevel)
                {
                    st.erase(it);
                }
            }
            string wrd=tmp.back();
            if (wrd==tw)
            {
                ans.push_back(tmp);
                continue;
            }
            for (int k=0;k<wrd.size();k++)
            {
                char a=wrd[k];
                for (char ch='a';ch<='z';ch++)
                {
                    wrd[k]=ch;
                    if (st.count(wrd))
                    {
                        tmp.push_back(wrd);
                        q.push(tmp);
                        usedonlevel.push_back(wrd);
                        tmp.pop_back();
                    }
                }
                wrd[k]=a;
            }
            
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends