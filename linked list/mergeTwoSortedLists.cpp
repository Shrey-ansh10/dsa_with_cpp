// LC-21 : Merge two sorted lists

// Given the head of two sorted lists, h1 and h2, merge the lists and return the head of the merged list
ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) { 

    //base case - if either of them becomes NULL, return the head to the other list, as elements in other list will be sorted already
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;

    if(h1->val <= h2->val){ // if value at h1 is smaller
        h1->next = mergeTwoLists(h1->next, h2); // move head to next node and pass the remaining list to recursive call
        return h1; // in above statement h1 will be connected to sorted merged list, so here we just return h1
    }else{
        h2->next = mergeTwoLists(h1, h2->next); // same as above logic
        return h2;
    }
}