#include <bits/stdc++.h>
using namespace std;

//min of two numbers
void minOfTwo(double a, double b){ // a and b are called parameters
    if(a<b){
        cout << "A is min of two."<< endl;
        //return a;
    } else if(b<a){
        cout << "B is min of two."<< endl;
        //return b;
    }
    else{
        cout<< "Both values are equal"<< endl;
    }
}

int main() {
	minOfTwo(5.8, 5.6); // 5.8 and 5.6 are called arguments. Arguments are the actual values passed in the function.
	//cout<< "Min = " << minOfTwo(10.5, 11.3)<< endl   
}