#include <bits/stdc++.h>
using namespace std;  
   
    bool isSafe(vector<string>& board, int r, int c, int n){ // TC: O(4n) -> O(n)
        
        // cond-1 : check that there's no queen in this row
        for(int i = 0; i<n; i++){
            if(board[r][i] == 'Q') return false;
        }

        // check id there's no queen in this column
        for(int i=0; i<n; i++){
            if(board[i][c] == 'Q') return false;
        }

        // check for top-left diagonal         
        for(int i=r, j=c; i >= 0 & j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        // check for top-right diagonal
        for(int i=r, j=c; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    // TC: O(n! x n)
    void nQueen(vector<string>& board, int n, int row, vector<vector<string>>& ans){

        //base case
        if(row == n){ 
            ans.push_back(board);
            
            for(string s : board){
                cout << s << endl;
            }
            cout << "-------------" << endl;
            
            return;
        }


        //selecting coulmn
        for (int col=0; col<n; col++){ //

            if(isSafe(board, row, col, n)){ //isSafe will check if the selected position on board satisfies all conditions - if it's safe to place queen at this cell

            board[row][col] = 'Q'; //place queen at safe place

            nQueen(board, n, row+1, ans); //recursively call itself for placing the queen in next row

            board[row][col] = '.'; //backtracking - while returning remove the queen from the place it was placed and move to next cell

            }
        }

    }


    vector<vector<string>> solveNQueens(int n) { // TC: O(n! x n)

        vector<string> board(n,string(n,'.')); //initilizing the board
        vector<vector<string>> ans; //vector of string to store the answer

        nQueen(board, n, 0, ans);

        return ans;
    }
    
    
    int main(){
        
        solveNQueens(4);
        
        return 0;
    }