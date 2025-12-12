// LC 232 : Implementing Queue using Stack 

#include<iostream>
#include<stack>
using namespace std;

// Approach-1 : Not very good as we write repetetive code in pop and front function.

class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
        
    }
    
    int pop() { 
        // this will happen in 3 steps

        // copy all elements in s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // 2. pop the element from s2
        int ans = s2.top(); // save the top element - to return it
        s2.pop(); // this will delete the top element of s2 - which is the front element of queue

        // 3. copy elements back to s2
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return ans;
        
    }
    
    int peek() {
        // this will also happen in 3 steps - similar to pop operation

        // copy all elements in s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // 2. pop the element from s2
        int ans = s2.top(); // this will delete the top element of s2 - which is the front element of queue

        // 3. copy elements back to s2
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return ans;
        
    }
    
    bool empty() {
        return s1.empty();       
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */




 // Approach - 2 : Better code  

class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {

    }
    
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
            return ;
        } 

        // if there are elements already in s1 - copy them to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // push the new element on s1
        s1.push(x);

        // copy back all elements from s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() { 
        int ans = s1.top(); // element at top / front
        s1.pop(); // remove it

        return ans; // return it
    }
    
    int peek() {
        int ans = s1.top(); 
        return ans;
    }
    
    bool empty() {
        return s1.empty();       
    }
};