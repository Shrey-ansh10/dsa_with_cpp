#include<iostream>
using namespace std;

// print nth fibonnacci series term
int fibonnacci(int n){ 
    int x = 0;
    int y = 1;
    int z;

    for(int i=0; i<n; i++){
        z=x+y;
        x=y;
        y=z;
    }   
    return x;
} 

int main(){
    int n;
    cout << "Enter the term of fibonnacci series you want: ";
    cin >> n;

    cout << "The " << n << "th term of fibonnacci series is: " << fibonnacci(n) << endl;
    return 0;
}