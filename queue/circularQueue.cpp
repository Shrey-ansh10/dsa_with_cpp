// Implementing Circular Queue - using array

// As it's implemented using array we will keep the size FIXED

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class CircularQueue{
// data members will be private
private:
    Node* head;
    Node* tail;
    // int size; // define size - if we want a fixed size
    // int currentSize; // track the number of nodes when we have a fixed size

// methods will be public
public:

    CircularQueue(){ // can take size as input param if we need fixed size of circular queue
        head = tail = nullptr;
    }

    void push(int data){ // add to rear
        Node* newNode = new Node(data);

        // when list is empty
        if(head == nullptr){
            head = tail = newNode;
            tail->next = newNode; // making the nod circular
            return ;
        }

        tail->next = newNode; // pointing next of last node to newNode
        tail = newNode; // moving tail pointer to new node
        tail->next = head; // connecting the tail to head

    }

    void pop(){ // remove from front
        if(head == nullptr){ //
            cout << "Queue is empty" << endl;
            return ;
        }

        // when only one node remains
        if(head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
            return ;
        }

        Node* temp = head; // store node in a temp - so we can delete it later
        head = head->next; // mode head to next to current node
        tail->next = head; // point tail to new head
        delete temp; // delete the prev node

    }

    int front(){
        if(head == nullptr){
            cout << "Queue is Empty." << endl;
            return -1;
        }

        return head->data;
    }
    
    bool isEmpty(){
        return head == nullptr;
    }


    //destructor 
    ~CircularQueue(){

        // only proceed if there is atleast 1 element in the - in case of no elements nothing will happen
        // if(head != nullptr){
        //     while(head != tail){
        //         Node* temp = head;
        //         head = head->next;
        //         delete temp;
        //     }
        //     delete head;
        // head = nullptr;
        // tail = nullptr;
        // }

        //even simpler
        while(!isEmpty()){ // till the list is not empty
            pop(); // keep deleting nodes
        }
    }
};


int main(){

    CircularQueue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.pop(); // remove 
    q.push(4);

    while(!q.isEmpty()){
        cout << q.front() << " ";
        q.pop();
    }


    return 0;
}