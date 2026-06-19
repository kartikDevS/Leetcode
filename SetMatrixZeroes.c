// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1


void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {

    int rowFlags[200] = {0};   
    int colFlags[200] = {0};   

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                rowFlags[i] = 1;
                colFlags[j] = 1;
            }
        }
    }
    //this was good approach instead of doing each row element and each col element 0 instead u just check whether this element is a part of the row/ col that has to be 0
    
    for (int i = 0; i < matrixSize; i++) { 
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (rowFlags[i] == 1 || colFlags[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}
