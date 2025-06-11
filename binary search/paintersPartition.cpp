#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int mid){ // TC: O(n)
    int painters=1, boards=0;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]>mid) return false;

        if(boards+arr[i]<=mid){
            boards+=arr[i];
        } else{
            painters++;
            boards=arr[i];
        }
    }
    
    if(painters>m) return false;
    else return true;

} 


int paintersPartition(vector<int>& arr, int m){ // Time Complexity: O(log(range) *n)
    if(m>arr.size()) return -1; // if painters are more than boards

    int sum=0; //calculating range for binary search
    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
    }

    int st = 0, end = sum, ans = -1; //search space

    while(st<=end){ // O(log(range) *n)
        int mid = st + (end-st)/2;
        if(isValid(arr, arr.size(), m, mid)){
            ans = mid;
            end = mid-1;
        } else{
            st = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {40, 30, 10, 20};
    int m = 2;
    cout << paintersPartition(arr, m) << endl;  // ans=60
}