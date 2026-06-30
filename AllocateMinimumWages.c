bool canD(int maxC,int* quantities,int size,int stores){
    long long sum=0;
    for(int i=0;i<size;i++){
        sum+=(quantities[i]+maxC-1)/maxC;
    }
    return sum<=stores;
}


int minimizedMaximum(int n, int* quantities, int quantitiesSize) {
    int right=0;int left=1;
    for(int i=0;i<quantitiesSize;i++){
        if(quantities[i]>right){
            right=quantities[i];
        }
    }
    int ans=right;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(canD(mid,quantities,quantitiesSize,n)){
            ans=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}