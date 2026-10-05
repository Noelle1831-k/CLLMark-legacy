void filterOddNumbers(int *nums, int size, int *output, int *outputSize) {
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] % 2 != 0) {
            output[j++] = nums[i];
        }
    }
    *outputSize = j;
}