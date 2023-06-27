#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n){
    if(arr.size()==0)return NULL;
    if(arr.size()==1)return new TreeNode<int>(arr[0]);
    int mid = arr.size()/2;
    TreeNode<int> *root=  new TreeNode<int>(arr[mid]);
    vector<int>left(arr.begin(), arr.begin()+ mid), right(arr.begin()+mid+1, arr.end());
    root->left = sortedArrToBST(left, left.size());
    root->right = sortedArrToBST(right, right.size());
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    sort(preOrder.begin(),preOrder.end());
    return sortedArrToBST(preOrder, preOrder.size());
}