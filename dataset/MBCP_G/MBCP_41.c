void filterEvenNumbers(int nums[], int size, int result[], int *resultSize) {
    *resultSize = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] % 2 == 0) {
            result[*resultSize] = nums[i];
            (*resultSize)++;
        }
    }
}