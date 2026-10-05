int findLongestConseqSubseq(int arr[], int n) {
    if (n == 0) return 0;
    int longestStreak = 0;
    int currentStreak = 1;
    qsort(arr, n, sizeof(int), (int(*)(const void*, const void*))(
        [](const int* a, const int* b) {
            return (*a) - (*b);
        }
    ));
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i - 1]) {
            if (arr[i] == arr[i - 1] + 1) {
                currentStreak += 1;
            } else {
                longestStreak = (currentStreak > longestStreak) ? currentStreak : longestStreak;
                currentStreak = 1;
            }
        }
    }
    return (currentStreak > longestStreak) ? currentStreak : longestStreak;
}