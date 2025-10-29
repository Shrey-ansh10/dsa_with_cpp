// The goal problem is to find all possible paths in a maze

// Q. Given a 2d array of size nxn, find all possible paths to travel from (0,0) to (n,n)
// Cond: - The cell in matrix are 0 and 1, where 1 cn be travelled but 0 can't be
//      

#include<iostream>
#include<vector>
#include<string>
using namespace std;



//helper function
void nextStep(int r, int c, vector<vector<int>>& mat, string path, vector<string> &ans, int n){

    // conditions to check
    if(r<0 || c<0 || r>n-1 || c>n-1 || mat[r][c]==0 || mat[r][c] == -1) return;

    //base case
    if(r==n-1 && c==n-1){

        cout << path << endl;
        ans.push_back(path);
        return;
    }


    // mark visited cells
    mat[r][c] = -1;

    //next cell options
    nextStep(r+1, c, mat, path+"D", ans, n); // down
    nextStep(r-1, c, mat, path+"U", ans, n); // up
    nextStep(r, c-1, mat, path+"L", ans, n); // left
    nextStep(r, c+1, mat, path+"R", ans, n); // right

    //unmark while backtracking
    mat[r][c] = 1;

}

vector<string> findPath(vector<vector<int>>& mat){
    int n = mat.size();
    vector<string> ans;
    string path = "";
    nextStep(0, 0, mat, path, ans, n);

    return ans;
}


int main(){

    vector<vector<int>> mat = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    
    findPath(mat);

    return 0;
}