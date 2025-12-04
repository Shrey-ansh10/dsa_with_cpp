// previous smaller element

#include<vector>
#include<iostream>
using namespace std;

vector<int> prevSmallerElem(vector<int>& nums){

    vector<int> ans(nums.size(), 0);
    stack<int> st;


    for(int i=0; i<nums.size(); i++){
        
        while(!st.empty() && st.top() >= nums[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i] = -1;
        } else{
            ans[i] = st.top();
        }

        st.push(nums[i]);
    }
    
    return ans;
}

int main(){

    return 0;
}