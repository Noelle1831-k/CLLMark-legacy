int* twoUniqueNums(int* nums, int numsSize, int* returnSize) {
    int* count = (int*)calloc(numsSize, sizeof(int));
    int* returnArray = (int*)malloc(numsSize * sizeof(int));
    int i, j, index = 0;
    for (i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    for (i = 0; i < numsSize; i++) {
        if (count[nums[i]] == 1) {
            returnArray[index++] = nums[i];
        }
    }
    *returnSize = index;
    free(count);
    return returnArray;
}