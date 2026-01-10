// LC-865 : Smallest Subtree with all the Deepest Nodes
// Given the root of a binary tree, the depth of each node is the shortest distance to the root.

// Return the smallest subtree such that it contains all the deepest nodes in the original tree.

#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Solution Approach: Inspired from lowest common ancestor approach
// Do Post order Traversal -- keep tracking depth as you go down
// Each node returns {depth, root of subtree containing all depest nodes}
// At each Node we have following options:
// -> Left subtree has deeper nodes => return left's ans
// -> right subtree has deeper nodes => return right's ans
// -> Both subtrees have same level of depth => return depth and this root | i.e. {left.first, root}


// Helper Function - TC : O(n)
pair<int, TreeNode*> findAns(TreeNode* root, int depth) {
        
        if(root == nullptr) return {depth-1, nullptr};

        pair<int, TreeNode*> left = findAns(root->left, depth+1);
        pair<int, TreeNode*> right = findAns(root->right, depth+1);

        if(left.first > right.first) return left;
        else if(left.first < right.first) return right;
        else return {left.first, root};
}


// Main function
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    
    pair<int, TreeNode*> p = findAns(root, 0);
    return p.second;
}