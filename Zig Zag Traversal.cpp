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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root){
    // Write your code here!
    vector<int> ans;
		if (root == NULL)
			return ans;
        bool flag = true;
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> level;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				BinaryTreeNode<int> * node = q.front();
				q.pop();
				if (node->left )
					q.push(node->left);
				if (node->right )
					q.push(node->right);
				level.push_back(node->data);
			}
            if(flag == true){
                //ans.push_back(level);
                flag = false;
            }else{
                reverse(level.begin(),level.end());
                //ans.push_back(level);
                flag = true;
            }
            for(auto it : level)ans.push_back(it);
		}
    return ans;
}
