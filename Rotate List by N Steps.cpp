/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
      if(!head || !head->next)return head;
        int len = 1;
        Node * temp = head;
        while(temp->next){
            len++;
            temp = temp->next;
        }
     //    cout<<len<<" ";
     //    cout<<temp->val;
        temp ->next = head;
        k = k%len;
        int ptr = len - k;
        //temp = head;
        //ptr++;
        while(ptr!=0){
            temp = temp ->next;
            ptr--;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
}