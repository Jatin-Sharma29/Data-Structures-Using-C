int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int*result=(int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        result[i]=-1;
        for(int j=1;j<numsSize;j++){
            if(nums[(i+j)%numsSize]>nums[i]){
                result[i]=nums[(i+j)%numsSize];
                break;
            }
        }
    }
    *returnSize=numsSize;
    return result;
}
