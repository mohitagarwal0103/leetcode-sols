//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:



 bool canparse(unordered_map<string,bool>mp, string word)
        {
            int size=word.size();
            if(size==0){
                return true;
            }
            string temp="";
            for(int i=0;i<word.length();i++){
                temp+=word[i];
                if(mp.find(temp)!=mp.end() && canparse(mp,word.substr(i+1)))
                return true;
            }
            return false;
        }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map <string, bool > mp ;
        for(auto it : B)
        mp[it]=true;
        return canparse(mp,A)==true?1:0;
    }







// bool solve(int i,string s,unordered_map<string , bool>mp)
// {
//     if (s.size()==0)
//     return true;
//     string tmp="";
//     for (int j=0;j<s.size();j++)
//     {
//         tmp+=s[j];
//         if (mp[tmp] && solve(0,s.substr(j+1),mp));
//         {
//             cout<<i<<" "<<j<<" "<<tmp<<endl;
//             return true;
//         }
            
//     }
//     return false;
// }
//     int wordBreak(string s, vector<string> &b) {
//         unordered_map<string , bool>mp;
//         for (auto i:b)
//         {
//             mp[i]=true;
//         }
//         return solve(0,s,mp)?1:0;
//         //code here
//     }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends