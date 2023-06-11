#include <bits/stdc++.h>
using namespace std;
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    // Write your code here
    if(head==NULL) return NULL;
    LinkedListNode<int>*prev=NULL,*curr=head,*nxt=head->next;
    while(curr!=NULL){
        curr->next=prev;
        prev=curr;
        curr=nxt;
        if(nxt!=NULL)nxt=nxt->next;
    }
    return prev;
}