// implementing linkedlist from scratch

#include<iostream>
using namespace std;

class Node{ //this class will solely be used to create a new node in list

public: // properties of the new node
    int data; // data to store in that node
    Node* next; // pointer to next data node - will always be null for every new node

    Node(int val){ //constructor - creates the node object and assigning value to it's variable properties
        data = val; // storing the data in it
        next = NULL; // pointer to next node - will always be null when new node is created
    }
};

// new class called List to manage and create a list
class List{ 
    Node* head; // head pointer to point to the start of the list
    Node* tail; // tail pointer to point the last element of list

public:
    List(){ // initlizing the list
        head = tail = NULL;  // both head and tail point to NULL meaning the list is empty
    }

    // Functions we need for out list
    // 1. push_back() : to add elements to the end/back of the list

    // creating methods/function to insert elements at the end of the list
    void push_back(){

    }

    // 2. pop_back() : to remove the last elements of the list
    void pop_back(){

    }

    // unlike vectors, in lists we can insert and delete elements from front as well.
    // 3. push_front() : 
    void push_front(int val){ //takes in the value/data inserted at a node
        // creating a dynamic object
        Node* newNode = new Node(val); // created a pointer of type Node, that points to newly created node object. The new node is created using Node class
            
        // Case 1: when there's no element in the list
        if(head == NULL){
            head = tail = newNode;  //both point to this newly created node
            return;
        }else{  // Case 2 : list contains one or more object
            newNode->next = head;
            head = newNode; // update the head
            return;
        }
    }
    
    // 4. pop_front() :
    void pop_front(){

    }

    // print function to print the linkedlist
    void printLL(){
        Node* temp=head;
        while(temp != NULL){
            cout << temp->data << " " ; //print the data at this node
            temp = temp->next; // update temp pointer
        }
        cout << endl;
    }



};


int main(){

    List linkedList; // creating/declaring a linked list

    linkedList.push_front(1);
    linkedList.push_front(2);
    linkedList.push_front(3);

    linkedList.printLL();

    return 0;
}