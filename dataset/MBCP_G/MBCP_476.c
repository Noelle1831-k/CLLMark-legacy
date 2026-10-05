int bigSum(int nums[], int size) {
    if (size <= 0) {
        return 0; 
    }
    int max = nums[0], min = nums[0];
    for (int i = 1; i < size; ++i) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return max + min;
}