// LC 491 : Next Greater Elements - 1


#include<iostream>
#include<stack>
using namespace std;

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans(nums2.size(), 0);

        // 1. find next greater for all elements in nums2
        for(int i=nums2.size()-1; i>=0; i--){
            
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }


            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(nums2[i]);
        }

        // 
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    nums1[i] = ans[j];
                    break;
                }
            }
        }

        return nums1;
    }

