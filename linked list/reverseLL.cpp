// LC-206 : Reversing a linked list

#include<iostream>
using namespace std;

class Node{
public: 
    int data; 
    Node* next; 
    Node(int val){ 
        data = val;
        next = NULL;
    }
};

class List{ 
    Node* head; 
    Node* tail; 
public:
    List(){
        head = tail = NULL; 
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


 // Approach 1 - My made
Node* reverseList(Node* head) {
    if(head == NULL || head->next == NULL) return head; // if no element or only 1 element in Linked List

    Node* temp = head->next->next; // starts with 3nd node
    Node* temp2 = head->next;  // starts with 2nd node

    head->next = NULL; // update head to NULL before loop

    while(temp != NULL){ 
        temp2->next = head; //update 2nd nodes connection - now will point to head
        head = temp2; // update head to 2nd node
        temp2 = temp; // pointer pointing to 2nd node will now point to 3rd node
        temp = temp->next; // pointer pointing to 3rd will be updated to it's next node 
    }

    temp2->next = head; // finally update last node to point to it's previous node
    head = temp2; // update head to last node - optional - but then return temp2 at last
    
    return head; // or return temp2;
}


// Approach 2 - classic
Node* reverseList(Node* head) {
    
    if(head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    
    return prev;
}
