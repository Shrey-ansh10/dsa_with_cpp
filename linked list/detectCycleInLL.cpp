// check if a cycle exist in the LL
// LC-141


ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head; // initilize slow pointer
    ListNode* fast = head; // initilize fast pointer

    while(fast != NULL && fast->next != NULL){ //loop till we find a cycle or reach the end of LL
        slow = slow->next; // slow pointer moves by 1 point
        fast = fast->next->next; // fast pointer moves by 2 point

        if(slow == fast){ //if cycle exist both will be same at a point - cycle detected
            cout << "cycle detected" << endl; // exit loop
            return true;
        }
    }
    return fasle;

}

