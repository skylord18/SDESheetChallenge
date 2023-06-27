#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

bool isValidBST(BinaryTreeNode<int> *root, int lb, int ub){
    if(!root)return true;
    if(root->data>ub || root->data<lb)return false;
    return (isValidBST(root->left, lb, root->data-1) && isValidBST(root->right,root->data+1, ub ));
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isValidBST(root, INT_MIN, INT_MAX);
}