bool canP(int minD,int *stalls,int size,int cows){
    int cows_placed=1;
    int last_loc=stalls[0];
    for(int i=1;i<size;i++){
        if(stalls[i]-last_loc>=minD){
            cows_placed++;
            last_loc=stalls[i];

            if(cows_placed>=cows)return true;
        }
    }
    return false;
}

int aggressiveCows(int* stalls, int n, int c) {
    int cmp(const void*a,const void*b){
        return *(int*)a-*(int*)b;
    }
    qsort(stalls,n,sizeof(int),cmp);

    int left=1;
    int right=stalls[n-1]-stalls[0];

    int ans=0;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(canP(mid,stalls,n,c)){
            left=mid+1;
            ans=mid;
        }
        else{
            right=mid-1;
        }
    }   
    return ans; 
}