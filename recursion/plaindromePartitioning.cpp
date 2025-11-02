// LC-131 : Plaindrome Partiotioning
// Given a string s, do partition of "s" such that every substring of that partition is valid pliandrome. 
// e.g. s = "aab" -> output: [["a", "a", "b"], ["aa", "b"]]

#include<iostream>
#include<vector>
#include<string>
using namespace std;

    //function to check if the number is valid pliandrome
    bool isPalindrome(string& s, int st, int e) {
        // int left = st, right = e;  // Use local variables
        while(st <= e){
            if(s[st] != s[e]) return false;
            st++;
            e--;
        }
    return true;
    }

    void branching(string& s, vector<vector<string>>& ans, vector<string>& temp, int st){
        //base case
        if(st==s.length()){
            ans.push_back(temp);
            for(string t : temp){
                cout << "\"" << t << "\" ";    
            }
            cout << endl; 
            return ;
        }

        // partitioning logic
        for(int end = st; end<s.length(); end++){
            //check if left is palindrome
            if(isPalindrome(s, st, end)){
                // add left part to the temp vector
                string lp = s.substr(st, end-st+1);
                temp.push_back(lp);

                //recursive call
                branching(s, ans, temp, end+1);

                //removing the last added substring from temp vector
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string& s) {
        vector<vector<string>> ans;
        vector<string> temp;
        branching(s, ans, temp, 0);
        return ans;
    }


    int main(){

        vector<string> str = {"aab", "aaab", "abaa", "abcaa", "abbab"};
        for(string s : str){
            partition(s);
            cout << "----" << endl;
        }
        return 0;
    }