// Implementing Doubly Linked List and it's functions.

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        int data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyList{
    Node* head;
    Node* tail;

public:
    DoublyList(){
        head = tail = nullptr;
    }

    // print function
    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "<->" ;
            temp = temp->next;
        }

    }

    // 1. Push front 
    void push_front(int val){
        // first we need to create a new node
        Node* newNode = new Node(val);
        
        // Case-1 : The list is empty
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{ // Case-2 : the list is having one or more nodes
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // 2. Push back
    void push_back(int val){
        Node* newNode = new Node(val);

        // Case-1 : The list is empty
        if(head == nullptr){
            head=newNode;
            tail=newNode;
        }else{ // Case-2 : the list has one or more elements
            tail->next = newNode; //connect tail to the new node
            newNode->prev = tail; // connect new node after tail
            tail = newNode; // move tail pointer to new node
        }
    }

    // 3. Pop front
    void pop_front(){
        if(head == nullptr){ // Case-1 : list is empty
            cout << "No element in the list. Empty list." << endl;
            return ;
        }else if(head == tail){
            delete head;
            head = tail = nullptr; 
        }else{
            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
            head->prev = nullptr;
            delete temp;
        }
    }

    // 4. Pop back
    void pop_back(){
        if(head == nullptr){ // Case-1 : 
            cout << "No element in the list. Empty list." << endl;
            return ;
        }else if(head == tail){
            delete head;
            head = tail = nullptr; 
        }else{
            Node* temp = tail;
            tail = tail->prev; // move tail to second last element
            temp->prev = nullptr; //
            tail->next = nullptr;
            delete temp;
        }
    }


};


int main(){

    return 0;
}
