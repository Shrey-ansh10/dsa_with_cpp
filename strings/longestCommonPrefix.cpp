// LC-14 : Find longest common prefix from a array of strings.

#include<string>
#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    
    string s = "";
    
    for(int i=0; i<strs[0].length(); i++){
        char c=strs[0][i];
        for(int j = 1; j<strs.size(); j++){
            if(i>=strs[j].length() || c!=strs[j][i]) return s;
            
        }
        s.push_back(c);
    }
    return s;
}

int main(){

    vector<vector<string>> input = {{"flower", "flow", "flight"}, {"good", "god", "gone"}, {"append", "expand"}};

    for(vector<string> s : input){
        cout << "-> " << longestCommonPrefix(s) << endl;
    }
    return 0;
}