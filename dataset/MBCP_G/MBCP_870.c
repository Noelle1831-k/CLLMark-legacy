int sumPositivenum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > 0) {
            sum += nums[i];
        }
    }
    return sum;
}