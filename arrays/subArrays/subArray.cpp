#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// printing the sub array
void printSubarrays(vector<int>& arr) {  //O(n^3) time complexity
    int n = arr.size(); 

    for (int start = 0; start < n; start++) {
        vector<int> subarray; //this vector will be initilized at every instance of this loop
        for (int end = start; end < n; end++) {
            subarray.push_back(arr[end]); //appending the elements of the obtained subarray to the empty vector
            for (int num : subarray) { // subsequently printing the elements of the vector, which is also the subarray
                cout << num << " ";
            }
            cout << endl;
        }
    }
}

// function to get maximum sum of subarray
int maxSubArraySumBF(vector<int>& A){ // brute force approach with O(n^2) time complexity
    
    int maxSum = INT_MIN; // store the value to maximum sub-array sum.
    
    for(int i=0; i<A.size(); i++){
        int currentSum = 0;
        for(int j=i; j<A.size(); j++){
            currentSum += A[j];
            maxSum = max(currentSum, maxSum); // this will update a maxSum with the max value we get at any point for the sum of any sub array.
        }
    }
    return maxSum;
}

// KADANE'S ALGORITHM - Finding maximum subarray sum in O(n) time complexity
int maxSubArraySum(vector<int>& A){
    int maxSum = INT_MIN, localSum =0;
    
    for(int i=0; i<A.size(); i++){
        localSum += A[i];
        maxSum = max(localSum, maxSum);
        
        if(localSum<0){
            localSum=0; //resettig the localSum value to zero
        }
    }
    return maxSum;
}


int main() {
    std::vector<int> arr = {1,4,-2,7,3,-1,-5};
    
    cout << maxSubArraySum(arr) << endl;
} 