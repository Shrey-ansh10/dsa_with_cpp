#include <bits/stdc++.h>
using namespace std;

//Q. inverted praymid with num
int main() {

    int n = 4;
//    char ch = 'A';
 
    for(int i=0; i<n; i++){ //outer loop
    
        for(int j=0; j<i; j++){ //first inner loop for spaces
            cout << " ";
        }
        
        for(int j=0; j<n-i; j++){ // loop for num
            cout << i+1 << ' ';
        }
        cout << endl;
    }

    return 0;
}