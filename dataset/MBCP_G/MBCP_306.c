int maxSumIncreasingSubseq(int a[], int n, int index, int k) {
    int max_sum = 0;
    for (int i = 0; i <= index; i++) {
        if (a[i] < a[k]) {
            int sum = a[i];
            for (int j = i + 1; j <= index; j++) {
                if (a[j] > a[i] && a[j] < a[k]) {
                    sum += a[j];
                    i = j;
                }
            }
            max_sum = (max_sum > sum) ? max_sum : sum;
        }
    }
    return max_sum + a[k];
}
