// LC-112 : Path Sum

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return false;
    
    targetSum -= root->val;

    if(targetSum == 0){
        if(root->left==nullptr && root->right==nullptr) return true;
        // else return false;  - this is a crucial case, if sum becomes 0 but it's not a leaf node - there is a chance that the next node can have value 0
    }
    
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);  
}
