// LC 239 : Sliding Window Maximum
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

#include<iostream>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        // Solution Process
        // 1. Traverse through each element of the first window
        //      1.2 For each element check the elements in queue from back. 
        //          the element at back should be <= nums[i], if that's the case pop that element - dq.pop_back();    use a while loop
        //      1.3 After that add the current elements index in the queue - dq.push_back(i)

        // buy the end of step 1, the front of dq will be the max of first window 

        // 2. Now go over each element one by one.
        // save the front of dq to the ans array, as it's the max of prev window 
        //      2.1 For each element - check the queue from front and compare if the index is actually in bound of the current window, if not remove that -> dq.pop_front(); use a while loop
        //      2.2 Now again from the back, compar the curent element and the element at the back , if the back is <= current element, remove it - dq.pop_back() : use a while loop
        //      2.3 After looping enter the current inx to the back of queue - dq.push_back()

        // 3. Finally push the element at the front of queue to the ans - for the last window
        // 4. return the ans array

        // traverse on all elements of the first window
        for(int i=0; i<k; i++){ // 0 to k
            while(!dq.empty() && nums[dq.back()] <= nums[i]){ // for each element, check if the front of deque is <= current element - if yes, pop it from the queue
                dq.pop_back();
            }
            dq.push_back(i); // push the current index on the stack
        }


        for(int i=k; i<nums.size(); i++){
            // insert the element at the front to the ans array
            ans.push_back(nums[dq.front()]);

            // compare the idx with the indices in the queue
            while(!dq.empty() && dq.front() < i-k+1){ // 
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] <=nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            
        }

        ans.push_back(nums[dq.front()]);

        return ans;
    }


    // Althought there are multiple while loop inside the for loop, when we dru run the process we can observe the max run for the loop can be O(n)
    // Therefore TC : O(n) | SC : O(k)