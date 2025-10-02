// LC 78 Subsets: Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order


#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
using namespace std;

int c = 0;

//print all subsets using recursion
void printSubsets(vector<int>& a, vector<int>& sub, int n){ // takes an original array, a subset array(initially empty), and a initially chosen element from the originally array 
    
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
    
    

    sub.push_back(a[n]); // the current chose number is added to the subset
    
    // 1. recursion calls - include currently chosen element
    printSubsets(a, sub, n+1); // pass the original array, the subset, and next num

    sub.pop_back(); //the
    // 2. recursion calls - exclude current number
    printSubsets(a, sub, n+1);
    
    
}

int main() {
    vector<int> a = {1,2,3}; // the array is not having repeating elements
    vector<int> sub;
    
    printSubsets(a, sub, 0);
    
    return 0;
}
