#include <iostream>
#include <cmath>
using namespace std;


// decimal to binary.
long d2b(int dec){
    long ans=0;
    long int pow =1;
    
    while(dec>0){
        int rem = dec % 2;
        dec/=2;
        
        ans+=(rem*pow);
        pow *= 10;
    }
    return ans;
}


int main() {

    int num = 12456;   
    cout << "Obtained binary number is : "<< d2b(num);
    return 0; 
}