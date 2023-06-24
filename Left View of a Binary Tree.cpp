#include <bits/stdc++.h> 
using namespace std;
//***********************************************************

 //   Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

//***********************************************************

vector<int> getLeftView(TreeNode<int> *root){
    //    Write your code here
    vector<vector<int>> lot;
    vector<int> leftView;
    queue<TreeNode <int> *> q;
    if(root==NULL)return leftView;
    q.push(root);
    while(!q.empty()){
        vector<int> lvl;
        int sz = q.size();
        for(int i =0;i<sz;i++){
            lvl.push_back(q.front()->data);
            if(q.front()->left)q.push(q.front()->left);
            if(q.front()->right)q.push(q.front()->right);
            q.pop();
        }
        lot.push_back(lvl);
    }
    for(auto it: lot)leftView.push_back(it[0]);
    return leftView;
}