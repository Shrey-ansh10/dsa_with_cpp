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


// Level Order traversal - BFS on Binary Tree
void levelOrderTraversal(Node* root){
    queue<Node*> q; // will store nodes on same level in left->right order. Key to traverse all nodes at a level and then only proceed to next level
    q.push(root); // initially push the root node to the queue

    q.push(nullptr); // this to track new level of tree

    while(!q.empty()){ // till the queue is empty - print the element at frond and add it's left and right child to queue
        
        Node* curr = q.front();
        q.pop();

        // this if statement is to track new level of the tree f
        if(curr == nullptr){
            if(!q.empty()){
                cout << endl;
                q.push(nullptr);
                continue;
            }else{
                break;
            }
        }

        cout << curr->data << " ";
        
        if(curr->left != nullptr){
            q.push(curr->left); //push left child to queue
        }
        if(curr->right != nullptr){
            q.push(curr->right); // push right child to queue
        }
    }

}

int heightofBinarytree(Node* root){ //TC : O(n) as we visit every node in the tree

    // base case 
    if(root == nullptr) return 0;

    int leftHeight = heightofBinarytree(root->left);
    int rightHeight = heightofBinarytree(root->right);
    return max(leftHeight, rightHeight)+1;
}

int countNodes(Node* root){

    if(root == nullptr) return 0;

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return leftCount+rightCount+1;
}

// sum of nodes
int sumOfNodes(Node* root){

    if(root == nullptr) return 0;

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    return leftSum + rightSum + root->data;
}

int main(){

    vector<int> preOrder = {2, 3, 4, -1, -1, 5, -1, -1, 7, -1, -1};

    Node* root = buildTree(preOrder, -1); // will give idx -1 for start condition

    preOrderTraversal(root);
 
    return 0;
}