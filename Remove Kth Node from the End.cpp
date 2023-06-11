#include <bits/stdc++.h>
using namespace std;
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K){
    // Write your code here.
    Node *dummy = new Node();
    dummy->next = head;
    Node *slow = dummy, *fast = dummy;
    for(int i =0;i<K;i++)fast = fast->next;
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    slow ->next = slow->next->next;
    return dummy->next;
}







// #include <bits/stdc++.h>
// using namespace std;
// Node* removeKthNode(Node* head, int K){
//     // Write your code here.
//     Node* dummy = new Node();
//     dummy->next = head;
//     Node* slow = dummy;
//     Node* fast = dummy;
//     for(int i=1;i<=K;i++)
//     {
//         fast = fast->next;
//     }
//     while(fast->next!=NULL)
//     {
//         fast = fast->next;
//         slow = slow->next;
//     }
//     slow->next = slow->next->next;
//     return dummy->next;
// }