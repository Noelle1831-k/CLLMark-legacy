int maxLenSub(int arr[], int n) {
    if (n == 0) return 0;
    int maxLen = 1, currLen = 1;
    for (int i = 1; i < n; i++) {
        if (abs(arr[i] - arr[i-1]) == 1) {
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
            }
            currLen = 1;
        }
    }
    if (currLen > maxLen) {
        maxLen = currLen;
    }
    return maxLen;
}