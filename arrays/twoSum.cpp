// LC-1 Two Sum

#include <bits/stdc++.h>
#include<vector>
using namespace std;


// Q. Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

//You can return the answer in any order.


vector<int> twoSum(vector<int>& nums, int target) {

        // hashmap approach
            unordered_map<int, int> m;
    
            vector<int> ans;
    
            for(int i=0; i<arr.size(); i++){
                int first = arr[i];
        
                int sec = tar-first;
                if(m.find(sec) != m.end()) {
                    ans.push_back(i);
                    ans.push_back(m[sec]);
                    break;
                }
        
                m[first] = i;
            }
    
            return ans;


        
        // // Two-pointer approach - (Only works when we want to return the values itself, not the index)
        // int size = nums.size();
        // int i=0;
        // int j = size-1;
        // vector<int> returnVal;
        
        //     while(i<j){    
        //         int sum = nums[i]+nums[j];
        //             if(sum > target){
        //                 j--;
        //             } else if(sum<target){
        //                 i++;
        //             } else{
        //                 returnVal.push_back(i);
        //                 returnVal.push_back(j);
        //                 return returnVal;
        //             }
        //     }
            
            
            
            // Following is the brute force approach, with O(n) complexity.
            // for(int i=0; i<size; i++){

            //     for(int j=i+1; j<size; j++){
            //     sum = nums[i]+nums[j];
            //     if(sum == target){
            //         //cout << nums[i] << " " << nums[j] ;
            //         ret = {i,j};
            //     }
            // }

        //}
        //return returnVal;
    }


int main() {
    
    vector<int> a = {3,2,4};
    int tar = 17;
    std::vector<int> result = twoSum(a, tar);

    // Check if a solution was found and print the result
    if (!result.empty()) {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
} 
// Time complexity: O(n)
