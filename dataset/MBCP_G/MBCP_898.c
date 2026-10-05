int* extractElements(int* numbers, int size, int n, int* returnSize) {
    int* result = (int*)malloc(size * sizeof(int));
    int currentCount = 1, resultCount = 0;
    for (int i = 1; i < size; ++i) {
        if (numbers[i] == numbers[i - 1]) {
            currentCount++;
        } else {
            if (currentCount == n) {
                result[resultCount++] = numbers[i - 1];
            }
            currentCount = 1;
        }
    }
    if (currentCount == n) {
        result[resultCount++] = numbers[size - 1];
    }
    *returnSize = resultCount;
    return result;
}