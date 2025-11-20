// LC-430 : Flatten a linked list


#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) { // this function will return a flattened list

        //base case 
        if(head == nullptr) return head;

        Node* curr = head;

        while(curr != nullptr){ // till we reach the last element of this level
            if(curr->child != nullptr){ // if a child node points to a valid node/ non null value
                // 1. Flatten the list
                Node* nxt = curr->next; // storing the address of next node to prevent the remaining list

                curr->next = flatten(curr->child); // call the recursive function and connect the curr->next to the head of this flattened list
                curr->next->prev = curr; // reverse connection to maintain doubly list
                curr->child = nullptr; // setting the child pointer to null as we have connected it as next node in this list

                // 2. find tail of the flattened list
                while(curr->next != nullptr){
                    curr = curr->next;
                }

                // 3. Connect the tail wil the next node of upper level list
                if(nxt != nullptr){
                    curr->next = nxt; // connection with the connection that preserved the remaining list
                    nxt->prev = curr;
                } else{
                    delete nxt;
                }
            }

            curr = curr->next;
        }

        return head; // the function needs to return the head of the flattened list
        
    }
};
