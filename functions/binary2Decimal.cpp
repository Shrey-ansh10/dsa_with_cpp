#include <iostream>
#include <cmath>
using namespace std;

// binary to decimal
int b2d(int bin){
    int ans=0; // this will store the decimal number value, which we get after conversion
    int pow=1; // initializing the starting pow of 2, 2^0=1 , this will increase as pow*2
    
    while(bin>0){
        int rem = bin%10;
        ans = ans+(rem*pow); // can also be written as ans+=(rem*pow) 
        
        bin = bin/10; //this will remove the lastdigit from binary number
        pow*=2; // this will increase the power exponentially, 2^n
    }   
    return ans; // return ans as it stores our decimal value obtained from binary
}


int main() {
    int num = 100000000;
    cout << " Obtained decimal number is : "<< b2d(num) << endl; 
    return 0; 
}