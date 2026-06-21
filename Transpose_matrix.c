/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int ** arr=malloc(matrixColSize[0]*sizeof(int*));
    for(int i=0;i<matrixColSize[0];i++){
        arr[i]=malloc(matrixSize*sizeof(int));
    }
    *returnSize=matrixColSize[0];
    *returnColumnSizes = malloc(matrixColSize[0] * sizeof(int));
    for (int i = 0; i < matrixColSize[0]; i++) {
        (*returnColumnSizes)[i] = matrixSize;
    }

    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixColSize[0];j++){
            arr[j][i]=matrix[i][j];
        }
    }
    return arr;
}