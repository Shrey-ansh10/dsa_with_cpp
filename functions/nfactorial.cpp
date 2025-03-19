#include <bits/stdc++.h>
using namespace std;

//calculate N factorial
int factorial(int n){
    // using for loop
    int fact = 1;
    for(int i=1; i<=n; i++){
        fact = fact*i;
    }
    return fact; // mentioning the return value is important because without it, function will run, but not return the processed/calculate value. Also "return" statement is the last statement of the function. all the logic, function call etc. are written before the return statement.
}

int main() {
    cout<< "factorial = "<< factorial(5);  // the return value of the function is getting printed on screen.    
    return 0; //good to write but not mandatory, just apply for the "main" function
}