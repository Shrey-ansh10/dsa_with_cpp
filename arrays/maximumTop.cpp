// LC 2202 : Maximize the Topmost Element After K Moves

// You are given a 0-indexed integer array nums representing the contents of a pile, where nums[0] is the topmost element of the pile.

// In one move, you can perform either of the following:

// If the pile is not empty, remove the topmost element of the pile.
// If there are one or more removed elements, add any one of them back onto the pile. This element becomes the new topmost element.
// You are also given an integer k, which denotes the total number of moves to be made.

// Return the maximum value of the topmost element of the pile possible after exactly k moves. In case it is not possible to obtain a non-empty pile after k moves, return -1.

// Constraints:
// 1 <= nums.length <= 105
// 0 <= nums[i], k <= 109

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int maximumTop(vector<int>& nums, int k) {
        
        int n = nums.size();
        int top=-1;

        if(k == 0) return nums[0]; 
        if(n == 1 && k == 1) return -1;
        if(k==1 && n>1) return nums[1];

        int currPtr = 0; // track the top of array

        // 2 possible moves
        while(k>1){ 
            if(currPtr < n){ // pile is non empty
                top = max(top, nums[currPtr]); // put the top element to q
                currPtr++; // move the ptr - means mimic removing first element
                k--;
            }else if(currPtr == n && top!=-1){ // pile is empty - but k>1 - mimic adding a char
                if(n == 1 && k%2==0) return -1;
                else return top;
            }
        }

        if( top!=-1 && k==1 ){
            if( n==1 && currPtr==n) return top;
            else if (n==1 && currPtr==n-1) return -1;
            else if(currPtr < n-1 && top < nums[currPtr+1]) return nums[currPtr+1];
            else return top;
        }
        
        return -1;
}



int main(){

    vector<pair<vector<int>, int>> input = {
        {{5,2,2,4,0,6}, 4}, // ans = 5
        {{2}, 3},
        {{0}, 10000},
        {{91,98,17,79,15,55,47,86,4,5,17,79,68,60,60,31,72,85,25,77,8,78,40,96,76,69,95,2,42,87,48,72,45,25,40,60,21,91,32,79,2,87,80,97,82,94,69,43,18,19,21,36,44,81,99}, 2},
        {{35,43,23,86,23,45,84,2,18,83,79,28,54,81,12,94,14,0,0,29,94,12,13,1,48,85,22,95,24,5,73,10,96,97,72,41,52,1,91,3,20,22,41,98,70,20,52,48,91,84,16,30,27,35,69,33,67,18,4,53,86,78,26,83,13,96,29,15,34,80,16,49}, 15}, // ans=94
        {{68,76,53,73,85,87,58,24,48,59,38,80,38,65,90,38,45,22,3,28,11}, 1}, // ans = 76
        {{2,28,6,4,3}, 100000}, // ans=28
        {{4,6,1,0,6,2,4}, 0} // ans = 4
    };

    for(pair<vector<int>, int>& p : input){
        cout << maximumTop(p.first, p.second) << endl;
    }

    return 0;
}