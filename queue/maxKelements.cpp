// LC 2530 : Maximal Score After Applying K Operations
// Description : You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
// In one operation:
// choose an index i such that 0 <= i < nums.length,
// increase your score by nums[i], and
// replace nums[i] with ceil(nums[i] / 3).
// Return the maximum possible score you can attain after applying exactly k operations.

// The ceiling function ceil(val) is the least integer greater than or equal to val.

#include<iostream>
#include<vector>
using namespace std;

long long maxKelements(vector<int>& nums, int k) { // TC : O((n + k)log n)
    long long score = 0;
    
    // TC: (n log_n) to add elements in priority queue
    priority_queue<int> pq(nums.begin(), nums.end()); // instead of sorting at every loop, we can use a priority queue - it will keep the elements in sorted manner

    
    for(int m=0; m<k; m++){ // TC : O(k log_n)
        
        // sort(nums.begin(), nums.end()); // perform sorting at each step - use priority queue instead

        // choose the greatest element - last element
        int top = pq.top();
        pq.pop(); //remove the element from the queue

        // perform operation
        score += (long long)top; // add it to score
        pq.push(ceil(top/3.0)); // change the vaule and add it back to the queue
    }
    
    return score;
}

int main(){
    return 0;
}
