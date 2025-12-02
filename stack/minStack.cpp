// LC 155 : Design a Min Stack
// In addition to the push() pop() & top(), min stack has a function that keeps track of the minimum number in the stack.

#include<iostream>
#include<stack>
using namespace std;

// Approach - 1: Store pair of the number and the minimum value of stack from that point
class MinStack {
public:
    stack<pair<int, int>> st; //initilize a stack

    MinStack() {
        // st;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }else{
            int minVal = min(val, st.top().second);
            st.push({val,minVal});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

// Approach-2 : Storing the minimum value in a single variable 
// But this approach is a bit tricky and practically comsumes the same amount of storage - because pair<int, int> = long long int
class MinStack {
public:

    stack<long long int> st; //initilize a stack
    long long int minVal = NULL;

    MinStack() { //constructor
        // st;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minVal = val;
        }else{
            if(val<minVal){
                long long int val_ = (long long int)2*val - minVal;
                minVal = val;
                st.push(val_);
            }else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top() < minVal){
            minVal = (2*minVal) - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()< minVal){
            return minVal;
        }
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main(){

    return 0;
}
