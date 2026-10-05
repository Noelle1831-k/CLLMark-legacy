typedef struct {
    int height;
    int radius;
} Doll;
int compareDolls(const void *a, const void *b) {
    Doll *dollA = (Doll *)a;
    Doll *dollB = (Doll *)b;
    if (dollA->height != dollB->height) {
        return dollA->height - dollB->height;
    }
    return dollA->radius - dollB->radius;
}
int maxNestedDolls(Doll *dolls, int total) {
    int *dp = (int *)malloc(total * sizeof(int));
    int maxDolls = 0;
    for (int i = 0; i < total; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (dolls[j].height < dolls[i].height && dolls[j].radius < dolls[i].radius) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (maxDolls < dp[i]) {
            maxDolls = dp[i];
        }
    }
    free(dp);
    return maxDolls;
}
int mainDollFunction(int dataset) {
    int n, m;
    Doll ichiroDolls[100], jiroDolls[100];
    int ichiroCount, jiroCount;
    while (1) {
        if (dataset == 0) break;
        ichiroCount = dataset;
        for (int i = 0; i < ichiroCount; i++) {
            int hi, ri;
            if (scanf("%d %d", &hi, &ri) != 2) return -1;
            ichiroDolls[i].height = hi;
            ichiroDolls[i].radius = ri;
        }
        if (scanf("%d", &m) != 1) return -1;
        jiroCount = m;
        for (int i = 0; i < jiroCount; i++) {
            int hi, ri;
            if (scanf("%d %d", &hi, &ri) != 2) return -1;
            jiroDolls[i].height = hi;
            jiroDolls[i].radius = ri;
        }
        int total = ichiroCount + jiroCount;
        Doll *mergedDolls = (Doll *)malloc(total * sizeof(Doll));
        for (int i = 0; i < ichiroCount; i++) {
            mergedDolls[i] = ichiroDolls[i];
        }
        for (int i = 0; i < jiroCount; i++) {
            mergedDolls[ichiroCount + i] = jiroDolls[i];
        }
        qsort(mergedDolls, total, sizeof(Doll), compareDolls);
        int result = maxNestedDolls(mergedDolls, total);
        free(mergedDolls);
        printf("%d\n", result);
        if (scanf("%d", &dataset) != 1) return -1;
    }
    return 0;
}
