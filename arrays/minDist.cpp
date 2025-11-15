// Minimum Distance Between Three Equal Elements I
// Given an integer array nums.
// A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].
// The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.
// Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

// CONSTRAINS:
// 1 <= n == nums.length <= 100
// 1 <= nums[i] <= n

// Step 1: Group Indices by Value : For each number, collect all indices where it appears.
// Step 2: Find Minimum Distance : For each number with ≥ 3 occurrences, find the minimum distance among all possible triples.

#include<iostream>
#include<vector>
using namespace std;

// Approach 1 : TC= O(n^4) | SC = O(n)

int minimumDistance(vector<int>& nums) {
    int minDist = INT_MAX;
    bool found = false;
    
    // For each possible value
    for(int num = 1; num <= nums.size(); num++) {
        vector<int> indices;
        
        // Collect all indices where this number appears
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == num) {
                indices.push_back(i);
            }
        }
        
        // If we have at least 3 occurrences, check all triples
        if(indices.size() >= 3) {
            found = true;
            
            // Try all possible triples (i < j < k)
            for(int i = 0; i < indices.size(); i++) {
                for(int j = i + 1; j < indices.size(); j++) {
                    for(int k = j + 1; k < indices.size(); k++) {
                        int dist = abs(indices[i] - indices[j]) + 
                                   abs(indices[j] - indices[k]) + 
                                   abs(indices[k] - indices[i]);
                        minDist = min(minDist, dist);
                    }
                }
            }
        }
    }
    
    return found ? minDist : -1;
}


// Approach 2 : TC = O(n log-n) | SC = O()
int minimumDistance(vector<int>& nums) {
    int minDist = INT_MAX;
    unordered_map<int, vector<int>> indicesMap;
    
    // Group indices by value
    for(int i = 0; i < nums.size(); i++) {
        indicesMap[nums[i]].push_back(i); // for all unique numbers - create a vector to store all indices they appear at
    }
    
    // Check each number
    for(auto& [num, indices] : indicesMap) {
        if(indices.size() < 3) continue; //if a number appears less then 3 times skip for it
        
        // For sorted indices, the minimum distance triple will be consecutive
        // So we only need to check consecutive triples
        for(int i = 0; i <= indices.size() - 3; i++) { // for pair of 3 consicutive indices and store min dist
            int dist = abs(indices[i] - indices[i+1]) + 
                       abs(indices[i+1] - indices[i+2]) + 
                       abs(indices[i+2] - indices[i]);
            minDist = min(minDist, dist);
        }
    }
    
    return minDist != INT_MAX ? minDist : -1;
}