bool knows(matrix,int a,int b){
    return matrix[a][b]==1;
}

int findCandidate(int **matrix,int matrixSize){ //sqaure matrix

    int candidate=0;

    for(int i=1;i<matrixSize;i++){
        if(knows(candidate,i)){
            candidate=i;
        }
    }

    for(int i=0;i<matrixSize;i++){
        if(i==candidate)continue;

        if(knows(candidate,i))return -1;

        if(!knows(i,candidate))return -1;
    }
    
    return candidate;
}