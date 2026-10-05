double zeroCount(int nums[], int size) {
    int zero_count = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] == 0) {
            zero_count++;
        }
    }
    return (double)zero_count / size;
}