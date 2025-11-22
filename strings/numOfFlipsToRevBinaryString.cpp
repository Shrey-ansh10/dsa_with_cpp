// LC 3750 : Minimum Number of Flips to Reverse Binary String
// You are given a positive integer n.
// Let s be the binary representation of n without leading zeros.
// The reverse of a binary string s is obtained by writing the characters of s in the opposite order.
// You may flip any bit in s (change 0 → 1 or 1 → 0). Each flip affects exactly one bit.
// Return the minimum number of flips required to make s equal to the reverse of its original form.

#include<iostream>
#include<string>
using namespace std;


string decimalToBinaryString(int n) { // TC = O(log n)
        if (n == 0) {
            return "0";
        }

        string binaryString = "";
        while (n > 0) {
            binaryString += (n % 2 == 0 ? '0' : '1');
            n /= 2;
        }
        
        reverse(binaryString.begin(), binaryString.end()); // Reverse to get correct order
        return binaryString;
    }


    int minimumFlips(int n) { // if binary form of n is of length 'k' -> TC=O(k) | SC=O(k) <-- this exact time complexity
        // And as (log n) will be almost equal to length of string we can also say that TC = O(log n) <-- approx time complexity
        int count = 0;

        // turn the given number to binary
        string m = decimalToBinaryString(n);

        char st=0, end=m.length()-1; // taking 2 pointers

        while(st<=end){
            
            if(m[st] != m[end]){
                // turn m[st] to it's opposite
                if(m[st] == 0){
                    m[st] = 1;
                    count++;
                }
                else{
                    m[st] = 0;
                    count++;
                } 

                // turn m[ed] to 
                if(m[end] == 0){
                    m[end] = 1;
                    count++;
                }else{
                    m[end] = 0;
                    count++;
                }
            }

            st++;
            end--;
        }

        return count;
    }


int main(){

    cout << minimumFlips(10) << endl;
    cout << minimumFlips(19843) << endl;

    return 0;
}