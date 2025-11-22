// LC-20

#include<iostream>
#include<stack>
#include<string>
using namespace std;


    bool isValid(string s) {

        if(s.length() % 2 != 0) return false; // early exit - reduces the runtime by a bit

        stack<char> st;

        for(char i : s){
            if(i == '(' || i == '[' || i == '{'){ // place opening brackets on the stack - remember using '' will be used, because "" will mean it's a string literal, and the comparision will break
                st.push(i); //place the char on top of stack
            }
            else { // check for closing brackets
                if(st.empty()) return false; // if we directly encounter a closing bracket - this is a important edge case

                // if((i == ')' && st.top() == '(') || (i == ']' && st.top() == '[') || (i == '}' && st.top() == '{')) st.pop();
                // else return false;

                // instead of the above if - else condition, we can use this
                switch(i) {
                    case ')': if(st.top() != '(') return false; break;
                    case ']': if(st.top() != '[') return false; break;
                    case '}': if(st.top() != '{') return false; break;
                    default: st.push(i);
                }
                st.pop();
            }
        }
        return st.empty(); //makes sure if the opening brackets are closed with corresponding brackets
    }

    int main(){
        vector<string> input = {"{[()]}", "{(})", "{", "}", "})({})"};

        for(string s : input){
            cout << isValid(s) << endl;
        }
    }