// LC-25 Reverse Node in K group

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.


#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        // base case
        if(head == nullptr){
            return nullptr;
        }

        // 1. seperate k nodes
        while(count < k){
            if(temp == nullptr) return head;
            temp = temp->next;
            count++;
        }

        // 2. call recursve function on remaining list
        ListNode* nxt = reverseKGroup(temp, k);  // will return head and we will store it in a temp ptr named nxt

        // 3. join the seperated k nodes to the returned list, in a reversed manner
        
        count = 1; // set count to 0
        while(count < k){
            temp = head; // temp point to first node in K group
            head = head->next; // move head to next
            temp->next = nxt; // connecting first node to nxt 
            nxt = temp; // moving nxt to temp
            count++; 
        }

        head->next = nxt;

        return head; 
    }
};