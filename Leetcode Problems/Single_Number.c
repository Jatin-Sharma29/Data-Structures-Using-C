int singleNumber(int* nums, int numsSize) {
    int i=0,j=0,count=0,freq[numsSize];
    for( i=0;i<numsSize;i++){
        freq[i]=-1;
    }
    for( i=0;i<numsSize;i++){
        count=1;
        for(j=i+1;j<numsSize;j++){
            if(nums[i]==nums[j]){
                count++;
                freq[j]=0;
            }
        }
        if(freq[i]!=0){
            freq[i]=count;
        }
    }
    for(i=0;i<numsSize;i++){
        if(freq[i]==1){
        return nums[i];
        }
    }
    return -1;
}
