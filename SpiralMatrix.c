// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100


int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int total= matrixSize*matrixColSize[0];
    int top=0,left=0,bottom=matrixSize-1,right=matrixColSize[0]-1;
    int *result=malloc(total*sizeof(int));
    *returnSize=0;

    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++){
            result[(*returnSize)++]=matrix[top][j];
        }
        top++;
        
        for(int i=top;i<=bottom;i++){
            result[(*returnSize)++]=matrix[i][right];
        }
        right--;

        if(top<=bottom){
            for(int j=right;j>=left;j--){
                result[(*returnSize)++]=matrix[bottom][j];
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                result[(*returnSize)++]=matrix[i][left];
            }
            left++;
        }
    }
    return result;
}