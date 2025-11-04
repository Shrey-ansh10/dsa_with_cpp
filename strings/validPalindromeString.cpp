// LC 125: Given a string s, return true if it is a palindrome, or false otherwise.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(string s) {
    
        int st=0, end=s.length()-1;
        while(st<=end){
            //to chech for alpha numeric character
            if(!isalnum(s[st])) {st++; continue;}
            if(!isalnum(s[end])) {end--; continue;}

            if(tolower(s[st++]) != tolower(s[end--])) return false;
        }

    return true;
    }


int main(){

    vector<string> s = {"A man, a plan, a canal: Panama", "race a car"};

    for(string i : s){
        if(isPalindrome(i)){
            cout << i << " : is plaindrome";
        }else{ 
            cout << i << " : not a plaindrome";
        }
    }
    return 0;
}