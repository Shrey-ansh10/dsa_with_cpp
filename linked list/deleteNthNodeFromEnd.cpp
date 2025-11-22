// LC-19 : Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

#include<iostream>
using namespace std;

// Definition for a Node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == nullptr) return head;

        ListNode* first = head;
        ListNode* second = head;

        for(int i=0; i<n; i++){
            first = first->next;
        }

        if (first == nullptr) {
            return head->next;
        }

        while(first->next != nullptr){
            first = first->next;
            second = second->next;
        }

        ListNode* toDel = second->next; // store ptr to the node to delete
        second->next = second->next->next;
        toDel->next = nullptr;
        delete toDel;

        return head;
        
    }
};