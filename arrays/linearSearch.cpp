#include <bits/stdc++.h>
using namespace std;

// time compleity of linear search is O(n), because it searches through all the values available
int linearSearch(int arr[], int size, int target){
    
    for(int i=0; i<size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main() {
    int array[] = {1, 6, 8, 21, 19, 93, 22, 25, 39};
    int size = sizeof(array)/sizeof(int);
    int target = 25;
    
    cout << linearSearch(array, size, target) << endl; 
    
    return 0; 
}