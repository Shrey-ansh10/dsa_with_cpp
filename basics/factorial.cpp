#include <bits/stdc++.h>
using namespace std;

// Q. Print factorial of N mumbers
//    n! = 1 * 2 * 3 * 4 .... * n;


int main() {
    
    int N;
    cin >> N;
    int fact=1;
    
    for(int i=1; i<=N; i++){
        fact = fact*i;
        
    }
    cout<< "factorial is : "<< fact << endl;
    return 0;
}

