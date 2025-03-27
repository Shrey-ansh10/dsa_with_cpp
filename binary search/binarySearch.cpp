#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int k){ //iterative approach of binary search
// Time Complexity = O(log n)
// Space Complexity = O(1)
    
    int st = 0, end = nums.size()-1;
    
    while(st<=end){
        //int mid = (st+end)/2; // this can causeoverflow
        int mid = st + (end - st)/2 ;
        if(k>nums[mid]){
            st = mid+1;
        }
        else if(k<nums[mid]){
            end = mid-1;
        }
        else{
            return mid;  
        } 
    }
    return -1;
} 

int binarySearchRecursive(vector<int>& nums, int k, int st, int end){ //recursion approach
// Time Complexity = O(log n)
// Space Complexity = O(log n)
    
    if(st<=end){
        //int mid = (st+end)/2; // this can causeoverflow
        int mid = st + (end - st)/2 ;
        if(k>nums[mid]){
            binarySearchRecursive(nums, k, mid+1, end);
        }
        else if(k<nums[mid]){
            binarySearchRecursive(nums, k, st, mid-1);
        }
        else{
            return mid;  
        } 
    }
    return -1;
} 

int main() {

    vector<int> arr1 = {-1, 0,2,4,5,8,10,12}; //even numb of elements
    int ans = binarySearch(arr1, 10); 
    cout << ans << endl;
    
    vector<int> arr2 = {-1,0,2,4,5,10,12}; //odd
    cout << binarySearch(arr2, 2)<< endl;
    return 0; 
}