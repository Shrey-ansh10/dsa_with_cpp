// LC-1 Two Sum

#include <bits/stdc++.h>
#include<vector>
using namespace std;


// Q. Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

//You can return the answer in any order.


vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int i=0;
        int j = size-1;
        vector<int> returnVal;
        
            while(i<j){    
                int sum = nums[i]+nums[j];
                    if(sum > target){
                        j--;
                    } else if(sum<target){
                        i++;
                    } else{
                        returnVal.push_back(i);
                        returnVal.push_back(j);
                        return returnVal;
                    }
            }
            
            
            
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
        return returnVal;
    }


int main() {
    
    vector<int> nums = {2, 11, 7,15};
    int target = 9;
    
    vector<int> ans = twoSum(nums, target);
    cout << ans[0] << " "<< ans[1] << endl;

    return 0; 
} 
// Time complexity: O(n)