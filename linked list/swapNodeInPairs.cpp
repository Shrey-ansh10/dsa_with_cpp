// LC-24 : Swap nodes in pair 
// This problem is pretty similar to the LC-25, the only difference is that there the K is variable, here K is fixed to 2

#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // base case
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* nxt = swapPairs(head->next->next); // recursively calling itself on next to next node

        ListNode* temp = head;
        head = head->next;
        temp->next = nxt;
        head->next = temp;

        return head;
    }
};