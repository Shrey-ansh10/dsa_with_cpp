// LC-2130 :  Maximum Twin Sum of a Linked List

// Q. Maximum Twin Sum of a Linked List.
// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

// Constraints:
// -> The number of nodes in the list is an even integer in the range [2, 105].
// -> 1 <= Node.val <= 105

// -------------------------------------------
// SOLUTION
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
class Solution {
public:

    ListNode* reverse(ListNode* midHead){ //reverse list from center
        if(midHead == NULL || midHead->next == NULL) return midHead;

        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = midHead;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast !=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tail = reverse(slow); //reverse 2nd half

        // logic to calculate max twin sum
        int sum=0;
        while(tail != NULL){
            int localSum = head->val + tail->val;
            sum = max(localSum, sum);

            head = head->next;
            tail= tail->next;
        }
        return sum;
    }
};

// Don't use above code as is without understanding.