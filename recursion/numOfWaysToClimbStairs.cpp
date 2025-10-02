// Given N number of stairs, a person standing at the bottom wants to reach the top. 
// The person can climb either 1 stair or 2 stairs at a time. 
// Count the number of ways, the person can reach the top (order of steps does not matter).

#include <iostream>

using namespace std;  

// solving using recursion 
int numOfWays(int n){ // TC: O(2^n)  SC: O(n) - auxilary stack space
    //base case
    if(n==0) return 1; // we have reached the bottom
    if(n<0) return 0; // we have crossed the bottom stair and there is no -1 stair, so this is not a valid way

    //recursive case - ways to reach nth stair
    int ways = numOfWays(n-1) + numOfWays(n-2); // we can reach the nth stair either from (n-1)th stair or (n-2)th stair

    return ways; // we can reach the nth stair either from (n-1)th stair or (n-2)th stair
}

   

int main(){
    int numStairs;
    cin >> numStairs;
    
    cout << numOfWays(numStairs) << endl;

}


// can be solved using ds for optimal solution - dp, memoization, tabulation 
