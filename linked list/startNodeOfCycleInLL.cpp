// return the start node of cycle in linked list, if it exists.
// LC-142


// slow fast pointer approach - TC=O(n) | SC = O(1)

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

    while(slow != fast){   // when both will be equal again tha will be the start node
        slow = slow->next; // now we'll ove both pointer by 1 step
        fast = fast->next;
    }
    return slow; //return slow or fast, as both points to the same node -> start node
}