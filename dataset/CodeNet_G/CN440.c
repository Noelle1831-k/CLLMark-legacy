int maxConsecutiveLength(int n, int k, int *cards) {
    int *present = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i < k; i++) {
        if (cards[i] != 0) {
            present[cards[i]] = 1;
        }
    }
    int maxLength = 0, currentLength = 0, missingCount = 0;
    for (int i = 1; i <= n; i++) {
        if (present[i] == 1) {
            currentLength++;
        } else {
            if (missingCount == 0) {
                missingCount = 1;
                currentLength++;
            } else {
                maxLength = (currentLength > maxLength) ? currentLength : maxLength;
                currentLength = 0;
                missingCount = 0;
                i--;
            }
        }
    }
    maxLength = (currentLength > maxLength) ? currentLength : maxLength;
    free(present);
    return maxLength;
}