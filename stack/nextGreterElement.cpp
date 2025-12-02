// Find Immediate next greater Element for every element of the given array

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElem(vector<int>& nums){
    stack<int> s;
    vector<int> ans(nums.size(), 0);

    for(int i=nums.size()-1; i>=0; i--){ // traversing the array from last to first element

        while(!s.empty() && s.top() <= nums[i]){
            s.pop(); // pop the top element
        }

        // stack is empty
        if(s.empty()){
            ans[i] = -1; // no nextGreater element exist and hence place -1 as ans for that element
        }else{ // else if stack becomes empty
            ans[i] = s.top(); // nextGreater element is the top element
        }

        s.push(nums[i]); // place the current element on the top of the stack
    }
    return ans; //return ans
}


int main(){

    vector<vector<int>> input = {
        {2},
        {0,4,2,1,6,9,1},
        {6,7,4,2,3,5,9}
    };
    
    vector<int> op = nextGreaterElem(input[2]);

    for(int i : op){
        cout << i << endl;
    }
    
    return 0;
}