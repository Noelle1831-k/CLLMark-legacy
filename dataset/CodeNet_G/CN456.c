int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
int main() {
    int w[10], k[10];
    int i;
    for (i = 0; i < 10; i++) {
        scanf("%d", &w[i]);
    }
    for (i = 0; i < 10; i++) {
        scanf("%d", &k[i]);
    }
    qsort(w, 10, sizeof(int), compare);
    qsort(k, 10, sizeof(int), compare);
    int w_score = w[0] + w[1] + w[2];
    int k_score = k[0] + k[1] + k[2];
    printf("%d %d\n", w_score, k_score);
    return 0;
}