#define MAX_N 40000
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int canWin(int *myLevels, int *opponentLevels, int N, int k) {
    int wins = 0;
    for (int i = 0, j = 0; i < k; i++) {
        while (j < N && myLevels[i] > opponentLevels[j]) {
            j++;
            wins++;
        }
        if (wins > k / 2) return 1;
        if (j < N) j++;
    }
    return wins > k / 2;
}
int solve(int *myLevels, int *opponentLevels, int N) {
    qsort(myLevels, N, sizeof(int), compare);
    qsort(opponentLevels, N, sizeof(int), compare);
    int left = 1, right = N - 1;
    int answer = -1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (canWin(myLevels, opponentLevels, N, middle)) {
            answer = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return answer;
}
int myLevels[MAX_N];
int opponentLevels[MAX_N];