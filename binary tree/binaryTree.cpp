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

void inOrderTraversal(Node* root){ // O(n)

    if(root == nullptr) return; // if root is null means this is the end, to return to parent node

    preOrderTraversal(root->left); // recursive call on left subtree
    cout << root->data << " "; // print the data at root
    preOrderTraversal(root->right); // recursive call on right subtree
}

void postOrderTraversal(Node* root){ // O(n)

    if(root == nullptr) return; // if root is null means this is the end, to return to parent node

    preOrderTraversal(root->left); // recursive call on left subtree
    preOrderTraversal(root->right); // recursive call on right subtree
    cout << root->data << " "; // print the data at root
}

// Pre, In & Post defines when we travers the ROOT node
// Pre : we traverse root - left -right. root first
// In : we traverse left-root-right. root in in center/2nd
// Post : traverse left-right-root. root at last

int main(){

    vector<int> preOrder = {2, 3, 4, -1, -1, 5, -1, -1, 7, -1, -1};

    Node* root = buildTree(preOrder, -1); // will give idx -1 for start condition

    preOrderTraversal(root);
 
    return 0;
}