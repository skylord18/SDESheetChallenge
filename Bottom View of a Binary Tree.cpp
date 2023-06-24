#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int>topView;
    if(root==NULL)return topView; 
    queue<pair<TreeNode <int> *, int>> q;
    map<int, TreeNode <int> *> mpp;
    q.push({root,0});
    mpp[0] = root;
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        int level = top.second;
        if(mpp.find(level)==mpp.end())mpp[level] = top.first;
        if(top.first->left)q.push({top.first->left, level-1});
        if(top.first->right)q.push({top.first->right, level+1});
    }
    for(auto it : mpp)topView.push_back(it.second->val);
    return topView;
}
