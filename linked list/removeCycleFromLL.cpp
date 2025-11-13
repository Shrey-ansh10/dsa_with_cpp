// Remove cycle from linked list if it exists

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head; // initilize slow pointer
    ListNode* fast = head; // initilize fast pointer

    while(fast != NULL && fast->next != NULL){ //loop till we find a cycle or reach the end of LL
        slow = slow->next; // slow pointer moves by 1 point
        fast = fast->next->next; // fast pointer moves by 2 point

        if(slow == fast){ //if cycle exist both will be same at a point - cycle detected
            break; // exit loop
        }
    }

    if(fast == NULL || fast->next == NULL) return NULL; // if cycle doesn't exist - return null

    // if cycle does exist
    slow = head; // reinitilize slow with head

    //creat a pointer to track previous position of fast pointer
    ListNode* prev = NULL;

    while(slow != fast){   // when both will be equal again tha will be the start node
        slow = slow->next; // now we'll ove both pointer by 1 step
        prev = fast;
        fast = fast->next;
    }//by the end of this loop slow and fast will be pointing to the start node of cycle

    // to remove cycle, we will update the prev which is the last node, to point to null
    prev->next = NULL; 

    return slow; //return slow or fast, as both points to the same node -> start node
}