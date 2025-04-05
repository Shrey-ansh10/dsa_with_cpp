// leetcode 852

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int st=1, end=arr.size()-2; // start the solution with index 1 and end at n-2, because it's a mountain, peak cant be at edges
    
    while(st<=end){
        int mid = st + (end-st) / 2 ;
        
        if(arr[mid-1] < arr[mid] && arr[mid]>arr[mid+1]) return mid;

        else if(arr[mid-1]<arr[mid]) st=mid+1;
        else end = mid-1;
    }

    return -1;
}

int main(){
    vector<int> arr = {0,1,0};
    cout << peakIndexInMountainArray(arr) << endl;
}
// Time: O(logn), Space: O(1)

