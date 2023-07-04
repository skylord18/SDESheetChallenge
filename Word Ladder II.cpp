#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> s(wordList.begin(),wordList.end());
        
        queue<vector<string>> q;
        q.push({beginWord});
      
        vector<string> used;
        used.push_back(beginWord);
        int level=0;
        vector<vector<string>> ans;
        
        while(!q.empty()){
            vector<string> curr=q.front();
            q.pop();
            
            if(curr.size()>level){
                level++;
                for(auto it: used){
                    s.erase(it);
                }
            }
            
            string word=curr.back();
            if(word==endWord){
                if(ans.size()==0 || ans[0].size()==curr.size())
                ans.push_back(curr);
            }
           
            for(int i=0;i<word.size();i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        curr.push_back(word);
                        q.push(curr);
                        
                        used.push_back(word);
                        curr.pop_back();
                        
                    }
                    
                }
                word[i]=og;
            }
        }
        
        return ans;
        
    }
};
