#include <bits/stdc++.h> 
using namespace std;
struct Node{
	private:
	Node *links[26];
	bool flag = false;
	public:
		bool containsKey(char ch){
			return (links[ch - 'a'] != NULL);
		}
		void put(char ch, Node * node){
			links[ch - 'a'] = node;
		}
		Node *get(char ch){
			return links[ch - 'a'];
		}
		bool isEnd(){
			return flag;
		}
		bool setEnd(){
			flag = true;
		}
};
class Trie{
	private :
	Node *root;
	public:
	Trie(){
        // Write your code here.
        root = new Node();
    }
    void insert(string word){
    	Node *node = root;
    	for(int i =0;i<word.length();i++){
    		if(node->containsKey(word[i])){
    		}else{
    			node->put(word[i] , new Node());
    		}
    		node = node->get(word[i]);
    	}
    	node->setEnd();
    }
    bool search(string word){
    	Node * node = root;
    	for(int i =0;i<word.length();i++){
    		if(!node->containsKey(word[i]))return false;
    		node = node->get(word[i]);
    	}
    	return node->isEnd();
    }
    bool startsWith(string prefix){
    	Node *node = root;
    	for(int i =0;i<prefix.size();i++){
    		if(!node->containsKey(prefix[i]))return false;
    		node = node->get(prefix[i]);
    	}
    	return true;
	}
	bool checkifprefixExist(string word){
		bool fl = true;
		Node * node = root;
		for(int i =0;i<word.length();i++){
			if(node->containsKey(word[i])){
				node = node->get(word[i]);
				if(node->isEnd() == false)return false;
			}
		}
		return true;
	}
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto it: a){
    	trie.insert(it);
    }
    string longestPrefix = "";
    for(auto it : a){
    	if(trie.checkifprefixExist(it)){
    		if(it.length()>longestPrefix.length())longestPrefix = it;
    		else if(it.length() == longestPrefix.length() && it < longestPrefix)longestPrefix = it;
    	}
    }
    if(longestPrefix=="")return "None";
    return longestPrefix;
}