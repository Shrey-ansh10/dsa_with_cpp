// LC 37 Sudoku Solver: Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// The '.' character indicates empty cells.
// The given board contain only digits 1-9 and the character '.'.
// You may assume that the given Sudoku puzzle will have a single unique solution. The given board size is always 9x9.

// all approaches in this are bruteforce approaches only - TC: O(9^(n*n)) where n is 9 here, SC: O(1) ignoring the recursion stack space

#include <bits/stdc++.h>
using namespace std;


bool isValid(int row, int col, char dig, vector<vector<char>>& board){
    // checking all at once - more efficient way
    for(int i=0; i<9; i++){
        if(board[row][i] == dig) return false;
        if(board[i][col] == dig) return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == dig) return false; //this is particularly very interesting way to traverse through all cells of respective grid.
    }

    return true;
};

// bool isValid(int row, int col, char dig, vector<vector<char>>& board){

//         // checking all at once - more efficient way
//         for(int i=0; i<9; i++){
//             if(board[row][i] == dig) return false;
//             if(board[i][col] == dig) return false;
//             if(board[3*(row/3) + i/3][3*(col/3) + i%3] == dig) return false; //this is particularly very interesting way to traverse through all cells of respective grid.
//         }
        
//         // check for duplicate value in the row
//         for(int i=0; i<9; i++){
//             if(board[row][i] == dig) return false;
//         }

//         check for duplicate in column
//         for(int i=0; i<9; i++){
//             if(board[i][col] == dig+'0') return false;
//         }

//         // check in 3x3 grid - but for that we need to retrive the exact grid where this cell lays

//         to obtain the grid pos
//         int boxRow = (row/3)*3;
//         int boxCol = (col/3)*3;

//         for(int i=boxRow; i<boxRow+3; i++){
//             for(int j=boxCol; j<boxCol+3; j++){
//                 if(board[i][j] == dig) return false;
//             }
//         }

//         return true;
//     }
    
    // approach-1
    bool sudokuSolver(int row, int col, vector<vector<char>>& board){
        
        // base case
        if(row == 9) return true;

        int nextRow = row;
        int nextCol= col+1;

        if(nextCol == 9){
            nextRow = row+1;
            nextCol = 0;
        }

        // if a number is already present on at this cell
        if(board[row][col] != '.'){
            return sudokuSolver(nextRow, nextCol, board);
        } 

        //selecting a digit for this position and performing recursion
        for(char dig='1'; dig<='9'; dig++){ //dig<'10' will cause error as 10 is not a individual char, but 1 to 9 are.
            if(isValid(row, col, dig, board)){
                board[row][col] = dig;

                if(sudokuSolver(nextRow, nextCol, board)) return true;

                board[row][col]='.'; 
            }
        }
        return false;
    }

    // approach-2 
    bool sudokuSolver2(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='.'){
                    for(char dig='1'; dig<='9'; dig++){ //dig<'10' will cause error as 10 is not a individual char, but 1 to 9 are.
                        if(isValid(i, j, dig, board)){
                            board[i][j] = dig;

                            if(sudokuSolver2(board)) return true;

                            board[i][j]='.'; 
                        }
                    }
                    return false;
                }
            }
        }
        return true; // this will reach at last cell itself
    }
    
    void solveSudoku(vector<vector<char>>& board){
        // sudokuSolver(0, 0, board);  // approach-2 
        sudokuSolver2(board); // approach-2
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
    
    solveSudoku(board);
    
    // print the solved board
    for(auto v : board){
        for(auto c : v){
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
