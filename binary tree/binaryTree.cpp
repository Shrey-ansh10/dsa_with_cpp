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

int main(){

    vector<int> preOrder = {2, 3, 4, -1, -1, 5, -1, -1, 7, -1, -1};

    buildTree(preOrder, -1); // will give idx -1 for start condition
 
    return 0;
}