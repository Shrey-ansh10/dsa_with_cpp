// LC-39: Combination Sum
// Question & Conditions:
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


// Conditions:
// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40


#include<iostream>
#include<vector>
#include<set>
using namespace std;


// ---------- Approach 1 -------------
set<vector<int>> s; // this is to ensure we dont have duplicate arrays in out final ans

    //helper function that is called multiple times
    void combination1(vector<int>& can, int idx, int tar, vector<vector<int>>& ans, vector<int>& selected){

        //base cases
        if(idx == can.size() || tar < 0){
            return ;
        }

        if(tar == 0){
            if(s.find(selected) == s.end()){ //unique ans
                ans.push_back(selected);
                s.insert(selected);
            }
            return;
        }

        if(can[idx] > tar) return;

        selected.push_back(can[idx]); //selecting element at current pos
        //selections
        combination1(can, idx+1, tar-can[idx],  ans, selected); //once
        combination1(can, idx, tar-can[idx], ans, selected); //multiple selection

        //before the execultion call
        selected.pop_back(); //remove the element added, because it is elecluded
        combination1(can, idx+1, tar, ans, selected);
    }


    vector<vector<int>> combinationSum1(vector<int>& can, int target) {
        vector<vector<int>> ans; //stores final answer
        vector<int> sel; // to store selected elements in the current call stack branch
        sort(can.begin(),can.end());

        // check if only 1 element in the array and it's equal to target, return it
        if(can.size()==1 && can[0] == target){
            ans.push_back({can[0]});
            return ans;
        } else if(can.size()==1){
            return ans;
        }

        combination1(can, 0, target, ans, sel);
        return ans;
    }

// ------------------------------------

// ----------Approach 2 ------------
// this is a bit more efficient

// No global 'set' is needed anymore
// set<vector<int>> s; 

void combination2(vector<int>& can, int idx, int tar, 
                 vector<vector<int>>& ans, vector<int>& selected) {

    // 1. Correct Base Case: Found a solution
    // This MUST be checked BEFORE the 'out of bounds' check.
    if (tar == 0) {
        ans.push_back(selected);
        return;
    }

    // 2. Base Cases for stopping
    if (tar < 0 || idx == can.size()) {
        return;
    }

    // --- Recursive Choices ---

    // Choice 1: "Skip" the current element
    // This call will explore all combinations that DO NOT include can[idx]
    // (This fixes your main bug: we can now skip '7' to find '3')
    combination2(can, idx + 1, tar, ans, selected);

    // Choice 2: "Pick" the current element
    // (We only do this if it's not larger than the target)
    if (tar >= can[idx]) { 
        selected.push_back(can[idx]);
        
        // Call again with the SAME idx, since we can reuse the number
        combination2(can, idx, tar - can[idx], ans, selected);
        
        // Backtrack
        selected.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& can, int target) {
    vector<vector<int>> ans; //stores final answer
    vector<int> sel; // to store selected elements
    
    // The sort is not required, but it can sometimes make pruning
    // (like the 'if(can[idx] > tar)' check) more effective.
    // In our new structure, it's not necessary.
    
    // Remove the special 'can.size()==1' check, it's not needed.

    combination2(can, 0, target, ans, sel);
    return ans;
}

// --------------------------------

int main(){


    // test cases
    vector<vector<int>> test_input = {{2,3,6,7}, {5,2,3}, {2}, {3}, {8,7,4,3}};
    vector<int> test_targets = {7, 8, 2, 3, 11};

    // cout << test_input.size() << endl;

    vector<vector<int>> ans1;
    vector<vector<int>> ans2;

    for(int i=0; i<test_input.size(); i++){
        
        if(i!=0) cout << "\n ===================== \n";
        
        cout << "Answers from approach 1 :\n";
        
        ans1 = combinationSum1(test_input[i], test_targets[i]);
        // printing vector 1
        for(vector<int> v : ans1){
            cout << "[" ;
            for(int j : v){
                if(j==v[v.size()-1]){
                    cout << j;
                    break;
                }
                cout << j << " ";
            }
            cout << "]" ;
        }
        
        
        cout << "\nAnswers from approach 2 :\n";

        ans2 = combinationSum2(test_input[i], test_targets[i]);
        // printing vector 2
        for(vector<int> v : ans2){
            cout << "[" ;
            for(int j : v){
                if(j==v[v.size()-1]){
                    cout << j;
                    break;
                }
                cout << j << " ";
            }
            cout << "]" ;
        }

    }

    return 0;
}