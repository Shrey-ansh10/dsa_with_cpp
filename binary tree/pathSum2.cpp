// LC-113 : Path Sum 2 

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

void getPathSum(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& currPath){

    if(!root) return;

    targetSum -= root->val;
    currPath.push_back(root->val);

    if(!root->left  && !root->right && targetSum == 0){
            ans.push_back(currPath);
            // currPath.pop_back(); // remove the value from path sum
    }

    getPathSum(root->left, targetSum, ans, currPath);
    getPathSum(root->right, targetSum, ans, currPath);
    currPath.pop_back();

}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    vector<vector<int>> ans;
    vector<int> currPath; 

    getPathSum(root, targetSum, ans, currPath);

    return ans;
}