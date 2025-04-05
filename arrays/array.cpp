#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int marks[] = {45, 98, 88, 40, 65}; //the size of array is mentioned either in the [square brackets].
    //int size = sizeof(marks); // can be stored in a variable using sizeof
    // but sizeof will give us total bytes of storage used by array, not the number of data blocks, so to get that we can do as following
    
    int size = sizeof(marks)/ sizeof(int); // this will give us the actual size, which refers to number of data blocks. i.e 5
    
    cout << size << endl;

    int array[] = {1,2,3};
    
    //int array2[]; // this is a wrong way to declare array and will give a compilation error. Because when declaring array we need to specify either the size of the array or the data elements in the array which will tell the compiler about how much memory to allocate to the array.
    
    cout << array << endl; // this will give us some unknown value as output, which is actually the data associated with the pointer that tells the starting of an array.
    
    
    return 0; 
}