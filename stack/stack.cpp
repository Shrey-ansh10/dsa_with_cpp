// Implementing Stack

#include<iostream>
#include<vector>
#include<list>
using namespace std;


// Implementing a stack using a vector
class Stack{
    vector<int> vs; // vs for vector stack

    // All operations on stack happen in O(1) time
public:
    // insert/place a element on top of stack
    void push(int val){
        vs.push_back(val);
    }

    // get the element at the top of stack
    int top(){
        return vs[vs.size()-1]; // return the last element of the 
    }

    // remove the element from the top of stack
    void pop(){
        // int t = v[v.size()-1]; // if we want to return the element we're removing, we can do that as well
        vs.pop_back();
        // return t; // when doing this the return type of the function will change
    }

    // to check if the stack is empty 
    bool isEmpty(){
        return vs.size() == 0;
    }

};

// Implementing Stack using Linked List
class Stack{

    list<int> lls; // lls for linked list stack
    // head of the linked list will track the top element of the stack

public:
    void push(int val){
        lls.push_back(val);
    }

    void pop(){
        if(lls.size() == 0){ // to mitigate operation from empty stack and preventing error
            cout << "Empty Stack" << endl;
        } 
        lls.pop_front();
    }

    int top(){
        return lls.front(); // return the element at head
    }

    bool isEmpty(){
        return lls.size() == 0;
    }

};


// using stack from stl
#include<stack>

int main(){

    //stack from stl
    stack<int> stdStack;
    stdStack.pop();
    stdStack.push(10);
    stdStack.top();
    stdStack.empty(); // same as our is empty function


    return 0;
}