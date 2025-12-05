// LC : Next Grester Element 2


#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int> nextGreaterElementInCircularArray(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(nums.size(), -1); // initilize everything with -1
    stack<int> st;

    for(int i = 2*n; i>=0; i--){
        while(!st.empty() && st.top()<= nums[i%n]){
            st.pop();
        }

        if(st.empty()) ans[i%n] = -1;
        else ans[i%n] = st.top();


        st.push(nums[i%n]);
    }

    return ans; //return ans
}

int main(){

    return 0;
}