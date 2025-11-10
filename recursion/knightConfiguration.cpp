// LC - 2596 : Kinght Tour Configuration
// -> Given an 2D array of n x n size, consisting of disctic integers values from 0 to n*n-1
// -> A night can move in following 2 ways:
// 1. 2 square vertically and 1 horizontally
// 2. 2 squares horizontally and 1 vertically
// The night can only move to cell which has value 1 higher than current cell's value
// Return true if grid represents a valid configuration of the knight's movements or false otherwise.

// IMP Point ->  In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.

#include<iostream>
#include<vector>
using namespace std;


// approach 1 - using loops
bool checkValidGrid1(vector<vector<int>>& grid) {

        //edge cases where the night doesn't start at grid[0][0]
        if(grid[0][0] != 0) return false;

        int n = grid.size();
        int r =0, c =0; 
        

        // 2d array with all possible moves
        int moves[8][2] = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
    
        // Follow the path from 0 to n²-1
        int current = 0; // value at starting cell - we know it's always 0
        int max = n * n; // max value at a cell
        
        while(current < max - 1) { // makes sure we keep going till the cell with n*n-1 is not found
            bool foundNext = false;
            
            // Check all 8 possible knight moves
            for(int i = 0; i < 8; i++) {

                int nr = r + moves[i][0]; //pick a row and
                int nc = c + moves[i][1]; // column as next step
                
                // Check if the next selected step is inbound and if next value matches
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && // check for bound
                grid[nr][nc] == current + 1) { // check for value at next step
                    //if both are valid, move to that step, by updating the following

                    r = nr; //update row val
                    c = nc; //update col val
                    current = grid[nr][nc]; //
                    foundNext = true;
                    break;
                }
            }
            if(!foundNext) return false; // No valid move found
        }
        
        return true; // Successfully reached the end   
    }



// Approach 2 - using recursion
bool checkValidGrid2(vector<vector<int>>& grid, int r, int c, int n, int expVal){
    
    if(c <0 || r<0 || c > n-1 || r > n-1 || grid[r][c] != expVal) return false;

    if(expVal == n*n-1) return true;

    // all 8 moves - we will go to all cell and which ever 
    int ans1 = checkValidGrid2(grid, r+2,c-1, n, expVal+1);
    int ans2 = checkValidGrid2(grid, r+2,c+1, n, expVal+1); 
    int ans3 = checkValidGrid2(grid, r-2,c-1, n, expVal+1);
    int ans4 = checkValidGrid2(grid, r-2,c+1, n, expVal+1);
    int ans5 = checkValidGrid2(grid, r-1,c+2, n, expVal+1);
    int ans6 = checkValidGrid2(grid, r-1,c-2, n, expVal+1);
    int ans7 = checkValidGrid2(grid, r+1,c+2, n, expVal+1);
    int ans8 = checkValidGrid2(grid, r+1,c-2, n, expVal+1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}


int main(){

    vector<vector<vector<int>>> grid = { { {0,11,16,5,20}, {17,4,19,10,15}, {12,1,8,21,6}, {3,18,23,14,9}, {24,13,2,7,22} },
                                         { {0,3,6}, {5,8,1}, {2,7,4} }, 
                                         { {8,3,6}, {5,0,1}, {2,7,4} },
                                         {{24,11,22,17,4}, {21,16,5,12,9}, {6,23,10,3,18}, {15,20,1,8,13}, {0,7,14,19,2} }
                                    };

    
    for(vector<vector<int>> v : grid){
        cout << "Ans from 1" << checkValidGrid1(v) << endl;
        cout << "Ans from 2" << checkValidGrid2(v, 0, 0, v.size(), 0) << endl;
    }

    return 0;
}