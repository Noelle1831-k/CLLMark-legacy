void freqElement(int** nums, int rows, int cols) {
    int freq[1024] = {0};
    int total_elements = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ++freq[nums[i][j]];
            ++total_elements;
        }
    }
    for (int i = 0; i < 1024; ++i) {
        if (freq[i] > 0) {
            printf("{%d, %d} ", i, freq[i]);
        }
    }
}