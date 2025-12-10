// Design an LRU Cache

#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
public:

    // we'll use a doubly linked list to store the cache data
    class Node {
        public:
            int key, val;
            Node* prev;
            Node* next;

            Node(int k, int v){
                key = k;
                val = v;
                next = prev = nullptr;
            }
    
    };


    // head and tail node initilized
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);


    unordered_map<int, Node*> m; // map will store the key and the node where the key value pair is stored
    int limit;


    void addNode(Node* newNode){
        Node* oldHeadNext = head->next; // create a temp ptr pointing to the head->next
        
        head->next = newNode; // change head->next to the new node
        oldHeadNext->prev = newNode; // connect oldnext's previous ptr to the new node 

        newNode->prev = head; // connect new node's prev to head
        newNode->next = oldHeadNext; // new node's next to the node which was next to head
    }


    void delNode(Node* oldNode){ 
        Node* prevPtr = oldNode->prev; // temp pointer to hold prev connection
        Node* nextPtr = oldNode->next; // temp ptr to hold next connection

        // delete the node once the prev and next connections are preserved
        delete oldNode; 

        // connect the previous and next nodes of the deleted node, to each other
        prevPtr->next = nextPtr; 
        nextPtr->prev = prevPtr;
    }


    LRUCache(int capacity) {
        limit = capacity;
        // also connect head and node - giving a starting point to the DLL
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())  return -1;

        int ans = m[key]->val; // get the value to be returned to the user
        
        // delete the node
        Node* ansNode = m[key];
        m.erase(key); // delete the data from the hashmap
        delNode(ansNode); // delete the node itself using the delete function

        // as the node is accessed, it should be moved to the from making it most recently used cache
        // to add it as MRU - we'll create a new node and add it the head
        put(key, ans); // pass the key value to the put function - it will create the new node, add it to MRU cache and also add it to the hashmap
            
        return ans;
    
    }

    
    void put(int key, int value) {

        // EDGE CASE - if the a same key with different value is already in the list, we will need to rewrite it
        if(m.find(key) != m.end()){
            Node* node = m[key]; // take the node to be deleted
            m.erase(key); // remove the key-value from the hash map
            delNode(node); // delete the node - logic in the function
            // then proceed to create a new node with same key but different value
        }

        // if the cache capacity is reached
        if(m.size() == limit){ 
            // delete LRU data - this will be the node just before the tail node
            m.erase(tail->prev->key); // delete the data from the hash map 
            delNode(tail->prev); // delete the LRU node itself
        }

        // create a node and insert it at head - also store it's address to hashmap
        Node* newNode = new Node(key, value); // create a node
        addNode(newNode); // at it to linked list - logic in addNode() function
        m[key] = newNode; // store the key and node ptr in the hash map, to make the get function work in O(1) time        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */