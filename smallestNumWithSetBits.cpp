// You are given a positive number n.

// Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits

#include<iostream>
using namespace std;

int smallestNumber(int n) {
        
        // Find the smallest power of 2 greater than n
        int power = 1; // bits-> 1
        while (power <= n) { 
            // the ops are performed on the bits of value of power. 
            // So when power is 1 -> bits form is 1
            // after left shift bits become 10 and the vaule of power become 2
            // at every iteration, left shift heppens and vaule of power becomes 2 -> 8 -> 16 -> 32 ...

            power <<= 1;  // left shift 1 bit makes the bits -> 10 -> 100 -> 1000
            //keelps hapening till a number greater or equal to n is reached
        }
        // for 
        return power - 1;  // All bits set below this power 
}

int main(){

    cout << smallestNumber(8) << endl;

    return 0;
}