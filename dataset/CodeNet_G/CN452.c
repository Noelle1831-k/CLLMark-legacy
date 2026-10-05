#define MAX_N 1000
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int maxScore(int *P, int N, int M) {
    int maxScore = 0;
    int comb[MAX_N * MAX_N];
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            comb[count++] = P[i] + P[j];
        }
    }
    qsort(comb, count, sizeof(int), compare);
    for (int i = 0; i < count; i++) {
        if (comb[i] > M) continue;
        int remain = M - comb[i];
        int *res = (int *)bsearch(&remain, comb, count, sizeof(int), compare);
        if (res) {
            int sum = comb[i] + *res;
            if (sum > maxScore) maxScore = sum;
        } else {
            int low = 0, high = count - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (comb[mid] <= remain) {
                    if (comb[i] + comb[mid] > maxScore) {
                        maxScore = comb[i] + comb[mid];
                    }
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }
    return maxScore;
}