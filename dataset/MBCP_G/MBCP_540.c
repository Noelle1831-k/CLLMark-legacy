int findDiff(int arr[], int n) {
    int frequency[1001] = {0}, maxFreq = 0, minFreq = n + 1;
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }
    for (int i = 0; i < 1001; i++) {
        if (frequency[i] > 0) {
            if (frequency[i] > maxFreq) {
                maxFreq = frequency[i];
            }
            if (frequency[i] < minFreq) {
                minFreq = frequency[i];
            }
        }
    }
    return maxFreq - minFreq;
}