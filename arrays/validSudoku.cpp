// LC 36 Valid Sudoku: Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

#include <iostream>
#include<vector>
using namespace std;

bool isValid(int row, int col, char num, vector<vector<char>>& board){

        //check for duplicate value in the row
        for(int i=0; i<9; i++){
            if(i!=col && board[row][i] == num) return false;
        }
        
        // check for duplicate in column
        for(int i=0; i<9; i++){
            if(i!=row && board[i][col] == num) return false;
        }

        //check in 3x3 grid - but for that we need to retrive the exact grid where this cell lays

        //to obtain the grid pos
        int boxRow = (row/3)*3;
        int boxCol = (col/3)*3;

        for(int i=boxRow; i<boxRow+3; i++){
            for(int j=boxCol; j<boxCol+3; j++){
                if(i!=row && j!=col && board[i][j] == num) return false;
            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Check each row, column, and 3x3 box
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num != '.') {
                    if (isValid(i, j, num, board)) {
                        return true;
                    }
                }
            }
        }
        return false;   
    }

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},          
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool result = isValidSudoku(board);
    if(result){
        cout << "The Sudoku board is valid." << endl;
    } else{
        cout << "The Sudoku board is not valid." << endl;
    }
    return 0;
}