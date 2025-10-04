#include<iostream>
using namespace std;

string reverse(string s){
//reverse a string        
    int st=0, end = s.length()-1;
        while(st<=end){
            swap(s[st], s[end]);
            st++;
            end--;
        }
    // or we can also do as following
        //reverse(s.begin(), s.end());
    return s;    
}

bool isPalaindrome(string s){
    int st=0, end=s.length()-1;
    while(st<=end){
        if(s[st++] != s[end--]) return false;
    }
    return true;
}


int main(){
    string str = "racecar";
    cout << isPalaindrome(str)<< endl;
    cout << reverse(str) << endl;

    return 0;
}