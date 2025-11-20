// Implementing circular linked list

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node (int val){
        data = val;
        next = nullptr;
    }
};

class circularLL{
    Node* head;
    Node* tail;


public:
    circularLL(){
        head = tail = nullptr;
    }

    // 1. Push front - as it's circular there's no front, but we can call it insertAtHead
    void insertAtHead(int data){ 
        Node* newNode = new Node(data);

        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        } else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    // 2. similarly for push back we can call it insertAtTail
    void insertAtTail(int data){
        Node* newNode = new Node(data);

        if(head == nullptr){
            head = tail = newNode;
            tail->next = head;
        }else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // 3. removeFromHead
    void removeFromHead(){
        if(head == nullptr){ // no node in the list
            cout << "List is empty" << endl;
            return ;
        }else if(head == tail){ // only one node in the list
            delete head;
            head = nullptr;
            tail = nullptr;
        }else{
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = nullptr;
            delete temp;
        }
    }

    // 4. deleteFromTail
    void deleteFromTail(){
        if(tail == nullptr){
            cout << "Empty list" << endl;
        }else if(tail = tail->next){ // if only one element in the list
            delete tail;
            head = tail = nullptr;
        }else{
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            tail->next = nullptr; // remove the next pointer from tail node
            tail = temp; // move tail pointer to second last node
            temp = tail->next;
            tail->next = head; // connect second last node to head
            delete temp;
            temp = nullptr;
        }
    } 

};


int main(){




    return 0;
}

