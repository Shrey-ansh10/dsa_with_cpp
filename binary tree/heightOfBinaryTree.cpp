#include<iostream>
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

int heightofBinarytree(Node* root){ //TC : O(n) as we visit every node in the tree

    // base case 
    if(root == nullptr) return 0;

    int leftHeight = heightofBinarytree(root->left);
    int rightHeight = heightofBinarytree(root->right);
    return max(leftHeight, rightHeight)+1;
}

