#include<iostream>;
using namespace std;

//check armstrong number
bool isArmstrongNum(int n){  //time complexity: O(log n)
    int copyN = n;
    int sumOfCube =0;
    while(n>0){
        int dig = n%10;
        sumOfCube+= (dig * dig * dig);
        
        n/=10;
    }
    
    return sumOfCube==copyN;
}


int gcdBruteforce(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a==b) return a;

    int gcd=1;

    for(int i=1; i<min(a,b); i++){
        if(i%a==0 && i%b==0) gcd=i;
    }
    return gcd;
}

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a==b) return a;

    // euclid's algorithm
    // if(a>b) gcd(a-b, b); 
    // else gcd(a, b-a);

    // euclids algorith optimized
    if(a>b) return gcd(a%b,b);
    else return gcd(a, b%a);
}

int lcm(int a, int b){
    int m = gcd(a,b);
    return (a*b)/m ;
}

int main(){

    // if(isArmstrongNum(123)) cout<< "An Armstrong number" <<endl;
    // else cout<< "Not Armstrong" << endl;
    
    //find gdd/hcf
    gcdBruteforce(20,28);

    return 0;
}