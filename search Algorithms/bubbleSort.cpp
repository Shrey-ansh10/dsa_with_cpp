#include <bits/stdc++.h>
using namespace std;

// bubble sort

void bubbleSort(int arr[], int n){ // Time complexity: O(n^2)
    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
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
	bubbleSort(arr, n);
	printArray(arr, n);
}
