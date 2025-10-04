// LC-47: Permutations II
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

#include <bits/stdc++.h>
using namespace std;  
   
    void uniquePermutations(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            for(auto i: nums) cout << i << " ";
            cout << endl;
            return;
        }
        
        // Use a set to track used elements at this level to avoid duplicates
        unordered_set<int> used;
        
        for (int i = idx; i < nums.size(); i++) {
            // Skip if this element has already been used at this position
            if (used.count(nums[i])) continue;
            
            used.insert(nums[i]);
            swap(nums[idx], nums[i]);
            uniquePermutations(nums, idx + 1, ans);
            swap(nums[idx], nums[i]); // backtrack
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        uniquePermutations(nums, 0, ans);
        return ans;
    }
    
    
    int main(){
        vector<int> nums = {1,1,2,2};
        
        sort(nums.begin(), nums.end());
        
        permuteUnique(nums);
        
    }