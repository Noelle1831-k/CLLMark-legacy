bool increasingTrend(int* nums, int length) {
    for (int i = 1; i < length; i++) {
        if (nums[i] <= nums[i - 1]) {
            return false;
        }
    }
    return true;
}