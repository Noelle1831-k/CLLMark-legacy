int cmp_int(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main(void) {
    char buf[100], *tok;
    int w, r[12], ri[12], n, i, j, k;
    double dist[12][12], d;
    while (gets(buf) != NULL) {
        tok = strtok(buf, " ");
        sscanf(tok, "%d", &w);
        n = 0;
        while ((tok = strtok(NULL, " ")) != NULL) {
            sscanf(tok, "%d", &(r[n++]));
        }
        qsort(r, n, sizeof(int), cmp_int);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                dist[i][j] = sqrt(pow(r[i]+r[j], 2) - pow(r[i]-r[j], 2));
            }
        }
        for (i = 0, j = n - 1, k = 0; i < n / 2 + (n&1); i++, j--) {
            ri[k++] = i;
            ri[k++] = j;
        }
        d = r[ri[0]] + r[ri[n-1]];
        for (i = 1; i < n; i++) {
            d += dist[ri[i-1]][ri[i]];
        }
        if (d <= w) {
            puts("OK");
            continue;
        }
        for (i = 0, j = n - 1, k = 0; i < n / 2 + (n&1); i++, j--) {
            ri[k++] = j;
            ri[k++] = i;
        }
        d = r[ri[0]] + r[ri[n-1]];
        for (i = 1; i < n; i++) {
            d += dist[ri[i-1]][ri[i]];
        }
        if (d <= w) {
            puts("OK");
            continue;
        }
        puts("NA");
    }
    return 0;
}