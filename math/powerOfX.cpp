// Q. Check if Number n can be Sum of Powers of x, and return true if it can be and false if it cannot be.
// Q. Given two numbers n and x, find if n can be represented as sum of x^i where i >= 0.
// Eg: n = x^0 + x^1 + ... + x^k . or any such combination.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool checkPowersOfx(int n, int x) {
        
    while(n>0){
        int rem = n%x;
        if(rem>1){
            return false;
        }
        n/=x;
    }
    return true;
}

int main() {
    int n = 21;
    int x = 3;
    
    if (checkPowersOfx(n, x)==1) cout << "True"; 
    else cout << "False";

    return 0;
}