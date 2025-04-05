#include <bits/stdc++.h>
using namespace std;

//reversing an array - here we are using two pointer method | Start and End are thr two pointers
void reverseArray(int array[], int size){
    int start = 0; 
    int end = size-1;
    
    while(start < end){
        swap(array[start], array[end]);
        start++;
        end--;
    }

}

int main() {
    int array[] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(int);

   reverseArray(array, size);
   
   for (int i = 0; i < size; i++) {
        cout << array[i] << " "; 
    }
   
    return 0; 
}