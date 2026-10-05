int subset(int *ar, int n) {
    int frequency[100001] = {0};
    int numDistinctSubsets = 0;
    for (int i = 0; i < n; ++i) {
        if (frequency[ar[i]] == 0) {
            numDistinctSubsets++;
        }
        frequency[ar[i]]++;
    }
    return numDistinctSubsets;
}