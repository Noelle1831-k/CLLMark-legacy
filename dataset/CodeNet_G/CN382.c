int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
int main() {
    int N;
    scanf("%d", &N);
    int total_customers = 0;
    int *offers = (int *)malloc(300000 * sizeof(int));
    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &offers[total_customers]);
            total_customers++;
        }
    }
    qsort(offers, total_customers, sizeof(int), compare);
    int max_sales = 0;
    for (int i = 0; i < N; i++) {
        max_sales += offers[i];
    }
    printf("%d\n", max_sales);
    free(offers);
    return 0;
}