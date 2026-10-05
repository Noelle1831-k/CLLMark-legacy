int findOddPair(int* a, int n) {
    int oddCount = 0, evenCount = 0, i;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    return oddCount * evenCount;
}