int getOddOccurrence(int arr[], int arrSize) {
    int res = 0;
    for (int i = 0; i < arrSize; i++) {
        res ^= arr[i];
    }
    return res;
}