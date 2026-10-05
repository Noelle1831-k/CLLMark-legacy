int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int maximum_remainder(int *cards, int n, int q) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (cards[mid] >= q)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return (low == 0) ? (cards[n - 1] % q) : ((cards[low - 1] % q));
}
int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    int *cards = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &cards[i]);
    qsort(cards, N, sizeof(int), cmp);
    for (int i = 0; i < Q; i++) {
        int query;
        scanf("%d", &query);
        printf("%d\n", maximum_remainder(cards, N, query));
    }
    free(cards);
    return 0;
}