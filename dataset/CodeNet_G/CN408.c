#define MOD 1000000
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int main() {
    int N;
    scanf("%d", &N);
    int winner[N-1], loser[N-1], matches[N-1], count[N+1];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < N-1; i++) {
        scanf("%d %d", &winner[i], &loser[i]);
        matches[i] = loser[i];
        count[loser[i]]++;
    }
    qsort(matches, N-1, sizeof(int), compare);
    int orderings = 1;
    for (int i = 0; i < N-1; ) {
        int j = i;
        while (j < N-1 && matches[i] == matches[j]) j++;
        orderings = (orderings * (j - i + 1)) % MOD;
        i = j;
    }
    printf("%d\n", orderings);
    return 0;
}