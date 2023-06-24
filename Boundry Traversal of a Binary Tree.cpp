#include <bits/stdc++.h> 
using namespace std;

/************************************************************

    Following is the Binary Tree node structure:
    
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
#include <bits/stdc++.h>

bool isLeaf(TreeNode<int> *root) { return !root->left and !root->right; }

void addLeftBoundary(TreeNode<int> *root, vector<int> &ans) {
  TreeNode<int> *curr = root->left;
  while (curr) {
    if (!isLeaf(curr))
      ans.push_back(curr->data);
    if (curr->left)
      curr = curr->left;
    else
      curr = curr->right;
  }
}

void addLeaves(TreeNode<int> *root, vector<int> &ans) {
  if (root->left)
    addLeaves(root->left, ans);

  if (isLeaf(root))
    ans.push_back(root->data);

  if(root->right)
    addLeaves(root->right, ans);
}

void addRightBoundary(TreeNode<int> *root, vector<int> &ans) {
  TreeNode<int> *curr = root->right;
  stack<int> s;
  
  while (curr) {
    if (!isLeaf(curr))
      s.push(curr->data);
    if (curr->right)
      curr = curr->right;
    else
      curr = curr->left;
  }

  while(!s.empty())
    ans.push_back(s.top()), s.pop();
}

vector<int> traverseBoundary(TreeNode<int> *root) {
  vector<int> ans;

  if (!root)
    return {};

  if (!isLeaf(root))
    ans.push_back(root->data);

  addLeftBoundary(root, ans);
  addLeaves(root, ans);
  addRightBoundary(root, ans);

  return ans;
}