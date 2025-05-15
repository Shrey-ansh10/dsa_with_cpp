#include <bits/stdc++.h>
using namespace std;

// selection sort

void selectionSort(int arr[], int n){ // Time complexity: O(n^2)
    
    for(int i=0; i<n-1; i++){ //selection loop : select an element
        int smallest = i;
        for(int j=i+1; j<n; j++){ //compare and sort
            if(arr[smallest]>= arr[j]) smallest=j;
        }
        
        swap(arr[i], arr[smallest]); // sort by swapping the smallest element with the i-th index element
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
	selectionSort(arr, n);
	printArray(arr, n);
}
