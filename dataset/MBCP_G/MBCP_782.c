int oddLengthSum(int* arr, int size) {
    int totalSum = 0;
    for (int start = 0; start < size; start++) {
        for (int length = 1; start + length <= size; length += 2) {
            for (int i = start; i < start + length; i++) {
                totalSum += arr[i];
            }
        }
    }
    return totalSum;
}