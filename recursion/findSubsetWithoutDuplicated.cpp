// LC 90: Subsets II - Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
using namespace std;

int c = 0;

    //print all subsets using recursion
    vector<vector<int>> ans; // a global variable to store the final ans

    //helper function - same as we one made initially - only the code inside of the if condition changes
    void findSubsets(vector<int>& a, vector<int>& sub, int n){ 
        
        //base case - terminal condition
        if(n == a.size()){
        c++;
        // cout << "value of count is " << c << endl;
        
        cout << "[" ;
        for (int i : sub){
            cout << i ;
            if( i == sub.back() ) continue;
            cout << " " ;
        }
        cout << "]" ;
        
        if( c == pow(2,n) ) return;
        
        cout << ", " ;
        return;
    }

        sub.push_back(a[n]); // the current choosen number is added to the subset
        
        // 1. inclusion calls - include currently chosen element
        findSubsets(a, sub, n+1); // pass the original array, the subset, and next num

        sub.pop_back(); //removing the last added number to subset array, before execlution call

        int idx = n+1;
        while(idx<a.size() && a[idx]==a[idx-1] ) idx++;

        // 2. execlusion calls - exclude current number
        findSubsets(a, sub, idx);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> sub; // creating array to store subset found at every terminal

        findSubsets(nums, sub, 0); //call the helper function and it will do everything
        
        return ans;    // finally return the ans stored in the global variable
    }

int main() {

    vector<int> a = {1,2,2};
    
    subsetsWithDup(a);
    
    return 0;
}

