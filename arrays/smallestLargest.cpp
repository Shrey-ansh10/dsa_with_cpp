#include <bits/stdc++.h>
using namespace std;

int main() {
    // find largest and smallest in array
    int marks[] = {45, 98, 88, 40, 65};
    int size = sizeof(marks)/ sizeof(int);
    
    int smallest = INT_MAX; //INT_MAX is used for infinity
    int largest =INT_MIN; // INT_MIN is used for positive infinity 
    
    int indexOfSmallest;
    int indexOfLargest;
    
    //to find the smallest
    for(int i=0; i<size; i++){
        if( marks[i] <= smallest){
            smallest = marks[i];
            indexOfSmallest = i;
        }
        
        //"min" a build in function can also be used insted of the if condition 
        //smallest = min(marks[i], smallest);
        
        
        // either If condition or the max function can be used to solve this.
        if(marks[i]>= largest){
            largest = marks[i];
            indexOfLargest = i;
        }
        //largest = max(marks[i], largest);
    }
    
//    cout << "Lowest Marks = " << smallest << endl;
//    cout << "Highest Marks = " << largest << endl;
    
    cout << "Index of Smallest is = "<< indexOfSmallest << endl;
    cout << "Index of Largest is = "<< indexOfLargest << endl;   
    
    return 0; 
}