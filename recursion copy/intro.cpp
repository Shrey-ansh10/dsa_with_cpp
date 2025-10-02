#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
using namespace std;


//this is just to understanding the implementation of recursion
int sumOfN(int n){
    if(n==1){ // base case - stopping condition
        return 1;
    }
    
    return n + sumOfN(n-1);
}


// (n+1)th term of fibonachi numbers/ sum of f(n)+f(n-1) - using in recursion
//  t(n) = t(n-1) + t(n-2) 
int fibonachi(int n){
    if(n == 0 || n == 1){
        return n;
    }
    
    return fibonachi(n-1) + fibonachi(n-2);
}

// check if an array is sorted or not, given the array and it's last index
bool isSorted(vector<int> arr, int last){
    if(last == -1 || last == 0) return true;
    
    return arr[last] >= arr[last-1] && isSorted(arr, last-1);
}

int main() {
    vector<int> a = {2};
    
    // cout << fibonachi(4) << endl;
    
    // cout << a.size();
    cout << isSorted(a, a.size()-1) << endl;
    return 0;
}