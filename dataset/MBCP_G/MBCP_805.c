int* maxSumList(int lists[][3], int listsSize, int* returnSize) {
    int maxSum = 0;
    int maxIndex = 0;
    for (int i = 0; i < listsSize; i++) {
        int currentSum = 0;
        for (int j = 0; j < 3; j++) {
            currentSum += lists[i][j];
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxIndex = i;
        }
    }
    int* maxList = lists[maxIndex];
    *returnSize = 3;
    return maxList;
}