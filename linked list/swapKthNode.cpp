// LC-1721 : Swap kth node in the linked list

#include<iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Approach 1 : TC: O(n)
ListNode* swapNodes(ListNode* head, int k){

    if(head == nullptr) return head;

    ListNode* first = head;
    ListNode* second = head;
    ListNode* kth = nullptr; 

    for(int i=1; i<k; i++){
        first = first->next;
    }

    kth = first;
    
    while(first->next != nullptr){
        first = first->next;
        second = second->next;
    }

    // swapping values
    int data = kth->val;
    kth->val = second->val;
    second->val = data;

    return head;
}


// Approach 2 : TC O(2n)
ListNode* swapNodes(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr) return head;

    ListNode* temp = head;
    int size = 1;

    while(temp->next != nullptr){
        temp = temp-> next;
        size++;
    }

    temp = head; // reset temp to head - will act as head pointer

    int kEnd = size-k+1; // determine the kth node from end of list, for which we want to change the value
    if (k == kEnd) return head; // same node

    ListNode* kSt = nullptr; // temp pointer to store the kth node from st
    ListNode* kEd = nullptr; // temp pointer to store the kth node from end

    int end = max(k, kEnd);
    for(int i=1; i <= end; i++){
        if(i == k){ // when we reach kth node
            kSt = temp; // point to it the kSt ptr
        }
        if(i == kEnd){ // when we reach kth node from end
            kEd = temp; // point the kEd ptr to it
        }
        temp = temp->next; // move temp to next
    }

    // swapping value logic
    int data = kSt->val;
    kSt->val = kEd->val;
    kEd->val = data;
    
    return head;
}