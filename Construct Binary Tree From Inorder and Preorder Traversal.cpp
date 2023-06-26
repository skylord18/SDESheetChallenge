#include <bits/stdc++.h> 
using namespace std;
/************************************************************

    Following is the TreeNode class structure

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

************************************************************/
TreeNode<int>*buildTree(vector<int>&inorder , int inStart, int inEnd, vector<int>& preorder, int preStart, int preEnd, map<int,int> inMap){
    if(inStart>inEnd || preStart>preEnd)return NULL;
    TreeNode<int> * node = new TreeNode<int>(preorder[preStart]);
    int inRoot = inMap[node->data];
    int numsLeft  = inRoot - inStart;
    node->left = buildTree(inorder, inStart, inRoot-1, preorder, preStart+1, preStart+numsLeft, inMap);
    node->right = buildTree(inorder, inRoot+1, inEnd, preorder, preStart + numsLeft +1, preEnd,inMap);
    return node;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder){
    //    Write your code here
    int inStart = 0, inEnd = inorder.size()-1, preStart = 0, preEnd = preorder.size()-1;
    map<int,int> inMap;
    for(int i = 0;i<inorder.size();i++)inMap[inorder[i]] = i;
    TreeNode<int> * root = buildTree(inorder, inStart, inEnd, preorder, preStart, preEnd, inMap);
    return root;
}