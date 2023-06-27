#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

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
