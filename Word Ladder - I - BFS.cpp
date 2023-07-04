#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string, int>> todo;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        todo.push({startWord,1});
        while(!todo.empty()){
            string word = todo.front().first;
            int steps = todo.front(). second;
            todo.pop();
            if(word == targetWord)return steps;
            for(int i =0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        todo.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};