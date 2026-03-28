int majorityElement(int* nums, int numsSize) {
    int candidate=nums[0];int count=1;
    for(int i=1;i<numsSize;i++){
        if(count==0){
            candidate=nums[i];
            count=1;
        }                             // remember this only works when majority element repeats more than n/2
        else if(nums[i]==candidate)count++;
        else{
            count--;
        }
    }
    return candidate;
}