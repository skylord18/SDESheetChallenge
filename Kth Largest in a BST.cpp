#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// vector<int> getInOrderTraversal(TreeNode *root){
//     vector<int>ans;
//     //getInOrderTraversal(root, ans);
//     TreeNode * node = root;
//     stack<TreeNode*> st;
//     while(true){
//         if(node != NULL){
//             st.push(node);
//             node  = node->left;
//         }else{
//             if(st.empty())break;
//             node =st.top();
//             st.pop();
//             ans.push_back(node->data);
//             node = node->right;
//         }
//     }
    
//     return ans;
// }

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
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
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    vector<int> x;
    inorderhelp(root,x);
    //inorder traversal
    int n=x.size();
    if(k>n){
        return -1;
    }
    return x[n-k];
    //return kth largest element.
}