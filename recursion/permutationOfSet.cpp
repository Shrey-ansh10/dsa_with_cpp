// LC: 46: Permutations - Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.    
    
#include <bits/stdc++.h>
using namespace std;  


void getPermute(vector<int>& nums, int idx, vector<vector<int>>& ans){

    // idx points to a index position where we are placing a number and finding permutations for other positions

    // base case
    if(idx == nums.size()){
        ans.push_back(nums); //add the current state - a unique permutation to the answer array
        
        for(auto i: nums) cout << i << " ";
        cout << endl;

        return ;
    }

    for(int i=idx; i<nums.size(); i++){

        swap(nums[idx], nums[i]); //swapping the i-th number with the idx

        getPermute(nums, idx+1, ans); //recursive call - this will give base case when idx==3

        swap(nums[idx], nums[i]); // rearranging the array to original form while backtracking to get the actual starting stage 
    }
}


vector<vector<int>> permute(vector<int>& nums) {
    
    vector<vector<int>> ans;
    getPermute(nums,0, ans);
    return ans;
}


int main(){

    vector<int> nums = {1,2,3};
    permute(nums);

}