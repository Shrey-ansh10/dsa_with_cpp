// LC-32 : Longest Valid Parentheses
// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

#include <iostream>
#include<string>
using namespace std;

int longestValidParentheses(string s) {
    
    stack<int> st; // creating stack
    st.push(-1);  // Initilizing with -1 -- base for length calculation 
    int maxLen = 0; // length
    
    for (int i = 0; i < s.length(); i++) { // loop on string
        if (s[i] == '(') { // if encounter a opening bracket 
            st.push(i); // push the index on stack
        } else { // in case of closing bracket - we will need to calculate string length
            
            st.pop(); // remove the top index from stack -- because it shows were the corresponding open bracket was present

            if (st.empty()) { // in case when stack becomes empty - cases where all opening brackets had a closing bracket or we directly encountered a closing bracket
                st.push(i);  // new base - insert the index on stack
            } else { // if stack is non empty - we will calculate the length
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen; // return max lenght
}