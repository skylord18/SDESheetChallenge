#include <bits/stdc++.h> 
using namespace std;
class Node{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    public:
    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    //creating reference trie
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    //to get the next node for traversal
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increrasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
};
class Trie{
    private:
        Node *root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *node = root;
        for(int i =0;i<word.length();i++){
            if(!node->containKey(word[i])){
                node->put(word[i], new Node());   
            }
            node = node->get(word[i]);
            node->increrasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *node = root;
        for(int  i = 0;i<word.length();i++){
            if(!node->containKey(word[i]))return 0;
            else node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *node = root;
        for(int i =0;i<word.length();i++){
            if(!node->containKey(word[i]))return 0;
            else node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node *node = root;
        for(int i =0;i<word.length();i++){
            if(node->containKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }else return;
        }
        node->deleteEnd();
    }
};
