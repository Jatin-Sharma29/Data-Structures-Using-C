int searchInsert(int* nums, int numsSize, int target) {
    int i=0,j=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]>=target){
            return i;
        }
    }
    return numsSize;
}
