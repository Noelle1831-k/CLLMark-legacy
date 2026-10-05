int longestSubseqWithDiffOne(int arr[], int n) {
    int *longest = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        longest[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j] + 1 || arr[i] == arr[j] - 1) {
                if (longest[i] < longest[j] + 1) {
                    longest[i] = longest[j] + 1;
                }
            }
        }
    }
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        if (maxLength < longest[i]) {
            maxLength = longest[i];
        }
    }
    return maxLength;
}