#include <bits/stdc++.h>
using namespace std;  


void getPermute(string& str, int idx, vector<string>& ans){

    // idx points to a index position where we are placing a number and finding permutations for other positions

    // base case
    if(idx == str.size()){
        ans.push_back(str); //add the current state - a unique permutation to the answer array
        
        for(auto i: str) cout << i << " ";
        cout << endl;
        
        return ;
    }

    for(int i=idx; i<str.size(); i++){

        swap(str[idx], str[i]); //swapping the i-th number with the idx

        getPermute(str, idx+1, ans); //recursive call - this will give base case when idx==3

        swap(str[idx], str[i]); // rearranging the array to original form while backtracking to get the actual starting stage 
    }
}


vector<string> permute(string& str) {
    
    vector<string> ans;
    getPermute(str,0, ans);
    return ans;
}


int main(){

    string w = "abcd";

    permute(w);

}