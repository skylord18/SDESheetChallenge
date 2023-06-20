#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int to;
    int size;

public:
    
    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        size = capacity;
        to = -1;
    }

    void push(int num) {
        // Write your code here.
        if(isFull()) return;

        to++;
        arr[to] = num;
    }

    int pop() {
        // Write your code here.

        if(isEmpty()) return -1;
        int ans = arr[to];
        to--;
        return ans;

    }
    
    int top() {
        // Write your code here.
        if(isEmpty()) return -1;

        return arr[to];

    }
    
    int isEmpty() {
        // Write your code here.
        return to==-1;
    }
    
    int isFull() {
        // Write your code here.

        return (to-1) == size;
    }
    
};