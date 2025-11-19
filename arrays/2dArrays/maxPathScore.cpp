// LC-3742 : Max Path Score in a Grid

// You are given an (m x n) grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.
// You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.
// Each cell contributes a specific score and incurs an associated cost, according to their cell values:
// 0: adds 0 to your score and costs 0.
// 1: adds 1 to your score and costs 1.
// 2: adds 2 to your score and costs 1. ​​​​​​​
// Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.
// Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

// Constraints:
    // 1 <= m, n <= 200
    // 0 <= k <= 103​​​​​​​
    // ​​​​​​​grid[0][0] == 0
    // 0 <= grid[i][j] <= 2
 

#include<iostream>
#include<vector>
using namespace std;

// Recursive Approach - TC = O(2^(m+n)) | SC=O(m+n)
// This is not a very good approach in terms of time complexity - enspecially given the grid size is mxn which can be at max 200 x 200

int recursiveSolver(vector<vector<int>>& grid, int r, int c, int k, int cost, int score){  

    int m = grid.size();
    int n = grid[0].size();

    // check for out of bound cell
    if( r>=m || c>=n) return -1;

    // calculate cost for this step
    if(grid[r][c] == 1 || grid[r][c] == 2) cost+=1; // if current cell has 1 or 2 increment by 1 else let it be as it is

    // calculate score for this step
    if(grid[r][c] == 1) score +=1;
    else if(grid[r][c] == 2) score+=2;

    // check if cost exceeds k
    if(cost > k) return -1;

    // check if we reached last cell - base case
    if( r == m-1 && c == n-1 ) return score;

    int right = recursiveSolver(grid, r+1,c, k, cost, score); // right
    int down = recursiveSolver(grid, r, c+1, k, cost, score); // down

    return max(right, down);

}

int maxPathScore(vector<vector<int>>& grid, int k) {

    return recursiveSolver(grid, 0, 0, k, 0, 0);     
}

int main(){
    vector<vector<vector<int>>> grids = {
        {{0,1}, {2,0}},
        {{0,1,1}, {1,2,1}, {1,2,2}}
    };

    vector<int> costs = {1, 5};
    
    for(vector<vector<int>> m :grids){
        for(int k : costs)
        cout << maxPathScore(m, k) << endl;
    }

    return 0;
}

// memoization can help make this solution more optimal
// DP will be the most optimal solution for this.