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
#include <bits/stdc++.h>
using namespace std;

string serializeTree(TreeNode<int> *root) {
  if (!root)
    return "";
  string str;
  queue<TreeNode<int> *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    while (n--) {
      auto p = q.front();
      q.pop();

      if (!p) {
        str += "#,";
        continue;
      }

      str += to_string(p->data) + ",";
      q.push(p->left);
      q.push(p->right);
    }
  }

  return str;
}

TreeNode<int> *deserializeTree(string &str) {
  if (str.empty())
    return NULL;

  stringstream s(str);
  string temp;

  getline(s, temp, ',');
  TreeNode<int> *root = new TreeNode<int>(stoi(temp));

  queue<TreeNode<int> *> q;
  q.push(root);

  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    getline(s, temp, ',');
    if (temp == "#")
      p->left = NULL;
    else {
      p->left = new TreeNode<int>(stoi(temp));
      q.push(p->left);
    }

    getline(s, temp, ',');
    if (temp == "#")
      p->right = NULL;
    else {
      p->right = new TreeNode<int>(stoi(temp));
      q.push(p->right);
    }
  }

  return root;
}




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
#include <bits/stdc++.h> 
using namespace std;
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
  if(!root)
            return "";
        string s = "";
        queue<TreeNode<int>*> todo;
        todo.push(root);
        while(!todo.empty()){
            TreeNode<int> *cur = todo.front();
            todo.pop();
            if(cur==NULL)
                s.append("#,");
            else{
                s.append(to_string(cur->data));
                s.append(",");
            }
                
            
            if(cur!=NULL){
                todo.push(cur->left);
                todo.push(cur->right);
            }
        }
        return s;

}

TreeNode<int>* deserializeTree(string &data)
{
 //    Write your code here for deserializing the tree
        if(data.size()==0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode<int> *root = new TreeNode<int> (stoi(str));
        queue<TreeNode<int>*> todo;
        todo.push(root);
        
        while(!todo.empty()){
            TreeNode<int>* node = todo.front();
            todo.pop();
            
            getline(s,str,',');
            if(str =="#"){
                node->left = NULL;
            }else{
                TreeNode<int> *leftChild = new TreeNode<int>(stoi(str));
                node->left = leftChild;
                todo.push(leftChild);
            }
            
            getline(s,str,',');
            if(str=="#"){
                node->right = NULL;
            }else{
                TreeNode <int>*rightChild = new TreeNode<int>(stoi(str));
                node->right = rightChild;
                todo.push(rightChild);
            }
        }
        return root;

}



