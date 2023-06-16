#include <bits/stdc++.h> 
using namespace std;
void generatePermutations(int Idx, string &ds,string &s , vector<int>&freq, vector<string>&ans){
    if(s.length()==s.length())ans.push_back(ds);
    for(int i = Idx;i<s.length();i++){
        if(freq[Idx]==0){
            ds+=s[Idx];
            freq[Idx] = 1;
            generatePermutations(Idx+1, ds, s, freq, ans);
            freq[Idx] = 0;
            ds.pop_back();
            
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    string ds = "";
    vector<int>freq(s.length(),0);
    generatePermutations(0,ds,s,freq,ans);
    return ans;
}