#include<iostream>
#include<vector>
using namespace std;

//linear search on matrix/2d-Array
pair<int,int> linearSearch(int mat[3][3], int r, int c, int k){
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            if(mat[i][j] == k){ 
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

//max row sum
int maxRowSum(int mat[3][3], int r, int c){
    int sum=0, maxSum =0;
    
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            sum += mat[i][j];
        }
        if(sum>maxSum) maxSum=sum;
        sum=0;
    }
    return maxSum;
}

//max column sum
int maxColSum(int mat[3][3], int r, int c){
    int sum=0, maxSum =0;
    
    for(int i=0; i<c; i++){ 
        for(int j=0; j<r; j++){ 
            sum += mat[j][i];
        }
        if(sum>maxSum) maxSum=sum;
        sum=0;
    }
    return maxSum;
}


//diagonal sum - only for square matrices
int diagonalSum(int mat[][3], int r){ //as we're using matrix, adjust the parameter as per size of matrix
    
    // int pdSum=0;
    // for(int i=0; i<r; i++){
    //     pdSum += mat[i][i];
    // }
    
    // int sdSum=0;
    // for(int i=0; i<r; i++){
    //     sdSum += mat[i][r-i-1];
    // }
    
    // if(r%2==1) return pdSum+sdSum-mat[r/2][r/2];
    // else return pdSum+sdSum;

    //better way to code above logic
    int sum=0;
    for(int i=0; i<r; i++){
        sum += mat[i][i];
        
        if(i!= r-i-1) sum+=mat[i][r-i-1]; //this will satisfy the condition of second loop
    }
    return sum;
}


int main() {

    //declaring an array
    int matrix[3][3];
    int rows = 3; //this shows number of rows, not the length of each row
    int columns = 3; //likewise with columns
    
    // Input on the matrix declared
    for(int i=0; i<rows;i++){ //outer loop track the row number
        for(int j=0; j<columns;j++){ //inner loop tracks column number
            cin >> matrix[i][j];
        }
    }
    
    // Output
    for(int i=0; i<rows;i++){
        for(int j=0; j<columns;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //initilizing an array with some values - not the only way, but one of the way
    int mat2[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    
    int key = 8;
    pair<int,int> p = linearSearch(mat2, rows, columns, key);
    // cout << p.first << "," << p.second << endl;

    // cout << maxRowSum(mat2, rows, columns) << endl;
    // cout << maxColSum(mat2, rows, columns) << endl;
    cout << diagonalSum(mat2, rows) << endl; //either of row or column can be sent as it only works for square matrix

    int mat3[4][4] = {{1,2,3,5},{4,7,9,1},{3,1,2,6},{8,4,1,7}};
    int r=4;
    //cout << diagonalSum(mat3, r) << endl;

    return 0; 
}