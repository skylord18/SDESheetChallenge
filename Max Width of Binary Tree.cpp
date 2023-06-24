#include <bits/stdc++.h> 
using namespace std;
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

int getMaxWidth(TreeNode<int> *root){
    // Write your code here.
        vector<vector<int>> ans;
		if (root == NULL)
			return 0;
		queue<TreeNode<int>*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> level;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				TreeNode <int> * node = q.front();
				q.pop();
				if (node->left )
					q.push(node->left);
				if (node->right )
					q.push(node->right);
				level.push_back(node->val);
			}
			ans.push_back(level);
		}
		int sz = 0;
        for(int i =0;i<ans.size();i++){
            if(ans[i].size()>sz)sz = ans[i].size();
        }
        return sz;
}