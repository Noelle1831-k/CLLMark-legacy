int maximumSum(int **list, int listSize, int *listColSize) {
    int maxSum = 0;
    for (int i = 0; i < listSize; ++i) {
        int currentSum = 0;
        for (int j = 0; j < listColSize[i]; ++j) {
            currentSum += list[i][j];
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    return maxSum;
}