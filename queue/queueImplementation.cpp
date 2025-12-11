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
public:
    Node* head;
    Node* tail;

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
        }else{
            Node* temp = head->next;
            head = head->next;
            delete temp;
        }

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
        if(head == nullptr) return true;
        else return false;
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