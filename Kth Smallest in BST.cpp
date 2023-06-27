#include <bits/stdc++.h> 
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
void inorderhelp(TreeNode<int>* root,vector<int>& x){
    if(root==NULL){
        return;
    }
    inorderhelp(root->left,x);
    x.push_back(root->data);
    inorderhelp(root->right,x);
    //inorder traversal
}
int kthSmallest(TreeNode<int> *root, int k){
	//	Write the code here.
    vector<int> inorder;
    inorderhelp(root, inorder);
    return inorder[k-1];
}