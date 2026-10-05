double positiveCount(int *nums, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > 0) {
            count++;
        }
    }
    return (double)count / size;
}