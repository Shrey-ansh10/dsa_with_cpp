#include <bits/stdc++.h>
using namespace std;

//  insertion sort : idea is to imagine the array in 2 parts, sorted and unsorted
//  select the first element from the unsorted array and place it ar the correct position in the sorted array

// insertion sort
void insertionSort(int arr[], int n){ // Time complexity: O(n^2)
    
    for(int i=1; i<n; i++){ //i is the first element of the unsorted part of array
        int curr = arr[i]; //first element of the unsorted part
        int j = i-1; // determines the correct position in sorted array, to place the element from unsorted array. It also bounds us to not move beyond 0-th index
        while(j >= 0 && arr[j]>curr){
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = curr;
    }
}



void printArray(int arr[], int n){
    
    cout << "[ " ;
    
    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
    
    cout << "]" ;
}

int main() {
	
	int arr[] = {4,5,2,3,1};
	int n = sizeof(arr) / sizeof(int);
	insertionSort(arr, n);
	printArray(arr, n);
}
