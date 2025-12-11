// Implementing a Queue from Scratch - using Linked List

#include<iostream>
using namespace std;

class Node{
public:
    Node* next;
    int data;
   
    Node(int val){
        data = val;
        next = nullptr;
    }
};


class Queue{

private:
    Node* head;
    Node* tail;

public:
    // constructor
    Queue(){
        head = tail = nullptr;
    }

    void push(int data){
        
        Node* newNode = new Node(data);

        if(head == nullptr){    
            head = newNode;
            tail= newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){

        if(head == nullptr){
            cout << "Queue is Empty" << endl;
            return ; 
        }
            
        Node* temp = head;
        head = head->next;

        // after popping the last element - properly handeling tail pointer to mitigate program crash
        if(head == nullptr){  // Queue is now empty
        tail = nullptr;   // Reset tail to nullptr
        }

        delete temp;
    }

    int front(){
        if(head == nullptr){
            cout << "Queue is Empty." << endl;
            return -1;
        }else{
            return head->data;
        }
    }

    bool empty(){
        return head == nullptr;
    }

    // destructor
    ~Queue(){
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main(){

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;

}