// LC - 225 : Implementing Stack using Queue

#include<iostream>
#include<queue>
using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;

    // As we will implement stack using queue - we will need to map the front of queue(the priority element of queue) to top of stack(the priority element of stack)
public:
    MyStack() {

    }
    
    void push(int x) { // TC: O(n)
        // push functionality will be done in 3 steps

        // 1. copy all the elements in q1 to q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // 2. push the new element to q1
        q1.push(x);

        // 3. copy all elements from q2 back to q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        } 
    }
    
    int pop() {
        int ans = q1.front(); // get the element at front/top
        q1.pop(); // remove the element fron q1
        return ans; // return the retrieved element
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */