#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// create a tree from preorder and return the root node - O(n) time
Node* buildTree(vector<int>& preorder, int idx){
    idx++;

    if(preorder[idx] == -1) return nullptr;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

void preOrderTraversal(Node* root){ // O(n)

    if(root == nullptr) return; // if root is null means this is the end, to return to parent node

    cout << root->data << " "; // print the data at root

    preOrderTraversal(root->left); // recursive call on left subtree
    preOrderTraversal(root->right); // recursive call on right subtree

}

int main(){

    vector<int> preOrder = {2, 3, 4, -1, -1, 5, -1, -1, 7, -1, -1};

    Node* root = buildTree(preOrder, -1); // will give idx -1 for start condition

    preOrderTraversal(root);
 
    return 0;
}