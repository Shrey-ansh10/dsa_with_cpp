// 2110 : Number of Smooth Descent Periods of a Stock
// You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.
// A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.
// Return the number of smooth descent periods.
// Constraints:
// 1 <= prices.length <= 10^5
// 1 <= prices[i] <= 10^5

#include<iostream>
#include<vector>
using namespace std;

long long getDescentPeriods(vector<int>& prices) {

    long long ans=0; 
    int n = prices.size();

    int length = 1; // the default length is one as per the question

    for(int i=1; i<=n; i++){ // start from first index and go till the size of array - one ove the last index
        if(i<n && prices[i] == prices[i-1]-1){ // if we/re in bound and find the continuous descend
            length++; // increment the length
        }else{ // when the continuity breaks 
            ans += (long long)length * (length+1) / 2; // calculate the answer using n * n+1 / 2 formula as in a continuous descent of n times, there will be n * n+1 / 2 smooth descends
            length = 1; // reset the lenght back to 1, before moving forward
        }
    }
    
    return ans;
}

int main(){
    vector<vector<int>> inputs = {
        {1}, // ans : 1 
        {9,8,7,6,2,1,1}, // ans : 14
        {8,6,7,7}, // ans : 4
        {3,2,1,4} // ans : 7
    };

    for(vector<int> v : inputs){
        cout << getDescentPeriods(v) << endl;
    }


    return 0;
}