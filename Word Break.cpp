#include <bits/stdc++.h> 
using namespace std;
bool f(int idx, string s, set<string>&st, vector<int> & dp){
        if(idx==s.length())return true;
        if(dp[idx]!=-1)return dp[idx];
        string temp = "";
        for(int i = idx;i<s.length();i++){
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                if(f(i+1, s, st, dp)==true)return dp[idx] =  true;
            }
        }
        return dp[idx] = false;
    }
bool wordBreak(vector < string >  wordDict, int n, string s) {
    // Write your code here.
        set<string> st;
        for(auto it : wordDict)st.insert(it);
        vector<int> dp(s.length(), -1);
        return f(0,s,st, dp);
}