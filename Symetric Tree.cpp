#include <bits/stdc++.h> 
using namespace std;
/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool checkifSymetric(BinaryTreeNode<int> * l, BinaryTreeNode<int>*r){
    if(l==NULL || r == NULL)return l==r;
    if(l->data!=r->data)return false;
    return checkifSymetric(l->left,r->right) && checkifSymetric(l->right, r->left);
}
bool isSymmetric(BinaryTreeNode<int>* root){
    // Write your code here.    
    if(root==NULL)return true;
    else return checkifSymetric(root->left, root->right);
    
}