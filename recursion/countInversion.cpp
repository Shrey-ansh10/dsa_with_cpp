// Count Inversion pairs from a given array
// An inversion pair is when folllowing 2 condition meet. 
// given arr[] a = {6,3,5,2,7};
// 1. 'i' < 'j'             [both are indexes]
// 2. arr[i] > arr[j]       [value at that index]

// so for the above arr, inversion pairs are => (6,3) (6,5) (6,2) (3,2) (5,2) => total pairs = 5;


// for this we'll use merge sort algorithm with slight modifications.

#include<iostream>
#include<vector>
using namespace std;

// change the return type | void -> int
int mergeSort(vector<int>& arr, int st, int mid, int end){
    vector<int> temp;
    int i = st, j = mid+1;
    int invCount=0;

    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else {
            invCount = mid-i+1; //
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    
    //copying sorted elements to original array
    for(int idx=0; idx<temp.size(); idx++){
        arr[st+idx] = temp[idx];
    }

    return invCount;
}

// change the return type | void -> int
int divide(vector<int>& arr, int st, int end){

    if(st<end){
        int mid = st + (end - st)/2;
        int leftCount = divide(arr, st, mid); // left half - returns inversion count
        int rightCount = divide(arr, mid+1, end); //right half - returns inversion count

        int count = mergeSort(arr, st, mid, end); // 

        return count + leftCount + rightCount;
    }

    return 0;
}

int main(){

    vector<int> a = {6,3,5,2,7};

    divide(a, 0, a.size()-1);

    return 0;
}