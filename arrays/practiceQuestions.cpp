#include <bits/stdc++.h>
using namespace std;

// Q. function to calculate sum and product of all numbers in array

int product(int array[], int size){
    int product = 1;
    for(int i=0; i<size; i++){
        product = product * array[i];
     } 
     return product;
}

int sum(int array[], int size){
    int sum = 0;
     for(int i=0; i<size; i++){
        sum = sum + array[i];
     } 
     return sum;
 }
 
 
// Q. functio to swap max and min numbers in array.

void swapMinMax(int array[], int size){
    int min = INT_MAX;
    int max = INT_MIN;
    int indexOfMin;
    int indexOfMax;
    
    for(int i = 0; i<size ; i++){
        if(array[i]<=min){
            min = array[i];
            indexOfMin = i;
        }   
        
        if(array[i] >= max){
            max= array[i];
            indexOfMax = i;
        }
    }
    
    cout << "Max Num : " << max << endl;
    cout << "Min Num : "<< min << endl;
    cout << "Index of Max before swap: " << indexOfMax << endl;
    cout << "Index of Min before swap: " << indexOfMin << endl;
    
    swap(array[indexOfMax], array[indexOfMin]);
    
    for(int i = 0; i<size ; i++){
        if(array[i]<=min){
            min = array[i];
            indexOfMin = i;
        }   
        
        if(array[i] >= max){
            max= array[i];
            indexOfMax = i;
        }
    }
    cout << "Index of Max after swap: " << indexOfMax << endl;
    cout << "Index of Min after swap: " << indexOfMin << endl;
    
}


// Q. function to print unique values in array. Unique value means non-repeating values.
void unique(int array[], int size){
    
    for(int i=0; i<size; i++){
        bool isUnique = true;
        
        for(int j=0; j<size; j++){
            if(i!=j && array[i]==array[j]){
                isUnique = false;
                break;
            }
        }
        if(isUnique){
        cout << array[i] << " ";
        }
    }
    
}


// Q. Function to print intersection of 2 array. Common values in two arrays. 
void findCommon(int arrA[], int arrB[], int sizeA, int sizeB){
    
    for(int i=0; i<sizeA; i++){ //all elements of A will be compared with all elements of B, therefore which array is bigger will not mattter
        for (int j=0; j<sizeB; j++){
            if(arrA[i]==arrB[j]){
                cout << arrA[i] << " ";
            }
        }
    }
}

int main() {
    int arrayA[] = {1, 4, 8, 9, 12, 15};
    int arrayB[] = {4, 10, 15, 20, 8};
    int size1 = sizeof(arrayA)/sizeof(int);
    int size2 = sizeof(arrayB)/sizeof(int);
    
    // cout << "Sum = " << sum(array, size) << endl;
    // cout << "Product = " << product(array, size) << endl;
    //unique(array, size);
 
    findCommon(arrayA, arrayB, size1, size2);
   
    return 0; 
}