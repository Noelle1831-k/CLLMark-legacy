int bigDiff(int nums[], int size) {
    if (size <= 0) return 0; 
    int maxVal = nums[0];
    int minVal = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
    }
    return maxVal - minVal;
}