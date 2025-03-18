#include<iostream>
using namespace std;

// Q. checkig if a number is prime or not

int main() {

    int N;
    cin >> N;  // Take input from the user
    
    int i=2;
 
    while(i<N-1){           // while loop approach
        if(N%i == 0){
            cout<< "This is a not a Prime Number" <<endl;
            break;
        }
        else{
            i++;
        }
    }


  /*  do{                   // do-while approach
        if(N%i == 0){
            cout<< "This is a not a Prime Number" <<endl;
            break;
        }
        i++;
    } while(i<=N-1); */
    
    cout<< "This is a Prime Number" << endl;
}
