int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int get_score(int *s, int n, int k) {
    int min_score = 0;
    qsort(s, n, sizeof(int), compare);
    for (int i = 0; i < k; i++) {
        min_score += s[i];
    }
    return min_score;
}
void amida(int n, int m, int h, int k, int *scores, int (*bridges)[2]) {
    int original_scores[n];
    for (int i = 0; i < n; i++) {
        original_scores[i] = scores[i];
    }
    int min_score = get_score(original_scores, n, k);
    for (int i = 0; i < m; i++) {
        int ai = bridges[i][0] - 1;
        int bi = bridges[i][1];
        int tmp = scores[ai];
        scores[ai] = scores[ai + 1];
        scores[ai + 1] = tmp;
        int current_score = get_score(scores, n, k);
        if (current_score < min_score) {
            min_score = current_score;
        }
        tmp = scores[ai];
        scores[ai] = scores[ai + 1];
        scores[ai + 1] = tmp;
    }
    printf("%d\n", min_score);
}