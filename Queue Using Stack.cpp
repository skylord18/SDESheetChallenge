#include <bits/stdc++.h> 
using namespace std;
// class Queue {
//     // Define the data members(if any) here.
//     stack<int> s1, s2;
    
//     public:
//     Queue() {
//         // Initialize your data structure here.
//         stack<int> s1, s2;
//     }

//     void enQueue(int val) {
//         // Implement the enqueue() function.
//         while(!s1.empty()){
//         	s2.push(s1.top());
//         	s1.pop();
//         }
//         s1.push(val);
//         while(!s2.empty()){
//         	s1.push(s2.top());
//         	s2.pop();
//         }
//     }

//     int deQueue() {
//         // Implement the dequeue() function.
//         if(s1.size()>0)return s1.top();
//         else return -1;
//     }

//     int peek() {
//         // Implement the peek() function here.
//         if(s1.size()>0)return s1.top();
//         else return  -1;
//     }

//     bool isEmpty() {
//         // Implement the isEmpty() function here.
//         return s1.size() ==0;
//     }
// };
class Queue {
    // Define the data members(if any) here.
    stack<int> input, output;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(!output.empty()){
        	int el = output.top();
        	output.pop();
        	return el;
        }else{
        	while(!input.empty()){
        		output.push(input.top());
        		input.pop();
        	}
            if(output.empty())return -1;
        	int el = output.top();
        	output.pop();
        	return el;
        }
    }

    int peek() {
        // Implement the peek() function here.
        if(!output.empty()){
        	return output.top();
        }else{
        	while(!input.empty()){
        		output.push(input.top());
        		input.pop();
        	}
            if(output.empty())return -1;
        	return output.top();
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(input.empty() && output.empty())return true;
        return false;
    }
};