// Implementing merge sort algorithm

#include<iostream>
#include<vector>
using namespace std;

void mergeSort(vector<int>& arr, int st, int mid, int end){
    vector<int> temp; 
    int i=st, j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i] < arr[j]){ // to sort in decending change the < to > and in the else if
            temp.push_back(arr[i]);
            i++;
        }else if(arr[j] < arr[i]){ // change < to >
            temp.push_back(arr[j]);
            j++;
        }
        else{ // handles cases when the array might have duplicate elements
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            i++, j++;
        }
    }

    // if one part is traversed and other is not
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
}

// divide function divides the array into two halves
vector<int> divide(vector<int>& arr, int st, int end){
    if(st<end){ // sereves as the base case and condition check
        int mid = st + (end-st)/2 ;

        divide(arr, st, mid); // left half

        divide(arr, mid+1, end); //right half

        mergeSort(arr, st, mid, end); // merge
    }
    return arr;
}

int main(){

    vector<int> arr = {10, 2, 8, 6, 7, 3, 1, 5, 4};
    divide(arr, 0, arr.size()-1);

    for(int i : arr){ //print sorted array
        cout << i << " " << endl;
    }

    // Time Complexity of Merge sort is : O(n * log_n)
    // Space Complexity is : O(n)

    return 0;
}