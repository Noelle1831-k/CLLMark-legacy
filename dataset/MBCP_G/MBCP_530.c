double negativeCount(int *nums, int size) {
    int negative_count = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] < 0) {
            negative_count++;
        }
    }
    return (double)negative_count / size;
}