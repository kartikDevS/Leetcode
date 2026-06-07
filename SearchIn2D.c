bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int n=matrixSize,m=matrixColSize[0];
    int left=0,right=n*m-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        int row=mid/m,col=mid%m;
        int val=matrix[row][col];
        if(target==val)return true;
        else if(target<val)right=mid-1;
        else{left=mid+1;}
    }
    return false;
}