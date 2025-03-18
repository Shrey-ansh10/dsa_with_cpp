#include <bits/stdc++.h>
using namespace std;

bool plaindrome(int a){
    int rev=0;
    int num = a;
    
	for(int i=0; num>0; i++){
	    int lastDigit = num%10;
	    
        if(i>0){
            rev = rev*10 + lastDigit;
        } else{
            rev = lastDigit;
        }
    
        num = num/10;
	}
    
    if(a==rev){
        //cout << "Number is Plaindrome" << endl;
        return 1;
    } else{
       // cout << "Not a Plaindrome" << endl;
        return 0;
    }
}


int main() {
	int x = -101;
 	
   cout << plaindrome(x) << endl;
	
}
