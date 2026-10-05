void divOfNums(int nums[], int size, int m, int n, int result[], int *resultSize) {
    int i;
    *resultSize = 0;
    for (i = 0; i < size; i++) {
        if (nums[i] % m == 0 || nums[i] % n == 0) {
            result[(*resultSize)++] = nums[i];
        }
    }
}