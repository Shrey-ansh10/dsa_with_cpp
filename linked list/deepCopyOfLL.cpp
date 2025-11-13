// LC -138
// create a deep copy of a LL which has random pointers


#include<iostream>
#include<unordered_map>
using namespace std;

// Definition for a Node.   
    class Node {
        public:
            int val;
            Node* next;
            Node* random;
            
            Node(int _val) {
                val = _val;
                next = NULL;
                random = NULL;
            }
    };



// Approach-1
Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        Node* newHead = new Node(head->val); // create a new node with value from head of original node, the new head for new node
        Node* temp1 = head->next; // a temp pointer pointing to 2nd node of original list 
        Node* temp2 = newHead; // a temp node which also points to the new head or 1st node of new list

        unordered_map<Node*, Node*> address; // creating a hash map
        address[head] = newHead;

        while(temp1 != NULL){
            Node* copyNode = new Node(temp1->val); // create a new node with value of next node in original list. Starts with 2nd node and goes till end

            address[temp1] = copyNode; //every original node will be mapped to it's new copy 
            
            temp2->next = copyNode; // previous node will now be linked to this new node
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // reinitilize temp pointers with head, so that we can traverse through both lists
        temp1 = head;
        temp2 = newHead;

        while(temp1 != NULL){
            temp2->random = address[temp1->random]; // temp1->random will return an address which will be assigned to the temp2->random. 
            // the address returned by adddress[temp1->random] will be the address of copy node which temp2's random pointer should point

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return newHead;
}


// Approach-2 : We will create nodes with value from original nodes and store their addresses maped with the original nodes they were created from
Node* deepCopy(Node* head){
    if(head == NULL) return NULL;

    unordered_map<Node*, Node*> map;

    // create new nodes and assign them value.
    // then store them in a hash map, mapped with the original node they were created from.
    Node* temp = head;
    while(temp != NULL){
        map[temp] = new Node(temp->val); // new node associated with head of first node
        temp = temp->next;
    }

    //re-initilize temp
    temp = head;
    while(temp != NULL){
        map[temp]->next = map[temp->next]; // assigning next
        map[temp]->random = map[temp->random]; // assigning temp
        temp = temp->next;
    }

    return map[head];

} 
