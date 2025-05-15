#include <bits/stdc++.h>
using namespace std;

// bubble sort

void bubbleSort(int arr[], int n){ // Time complexity: O(n^2)
    for(int i=0; i<n-1; i++){
        bool isSorted = true; //assume array is already sorted, in that case to avoid extra execution when the array is already sorted
        
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSorted = false;  //if array is not sorted, mark initial assumption false
            }
        }
        if(isSorted) break; // this will reduce the time complexity to 'O(n)' when the array is already sorted
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
