typedef struct {
    long long weight;
    long long count;
} BokkSolid;
int compare(const void *a, const void *b) {
    BokkSolid *solidA = (BokkSolid *)a;
    BokkSolid *solidB = (BokkSolid *)b;
    if (solidA->weight < solidB->weight) return -1;
    if (solidA->weight > solidB->weight) return 1;
    return 0;
}
void processBokk(long long *a, long long *b, int len) {
    BokkSolid *results = malloc(len * sizeof(BokkSolid));
    int resultCount = 0;
    for (int i = 0; i < len; i++) {
        long long weight = a[i] + b[i];
        long long count = 1LL << (a[i] < b[i] ? a[i] : b[i]);
        int merged = 0;
        for (int j = 0; j < resultCount; j++) {
            if (results[j].weight == weight) {
                results[j].count += count;
                merged = 1;
                break;
            }
        }
        if (!merged) {
            results[resultCount].weight = weight;
            results[resultCount].count = count;
            resultCount++;
        }
    }
    qsort(results, resultCount, sizeof(BokkSolid), compare);
    for (int i = 0; i < resultCount; i++) {
        printf("%lld %lld\n", results[i].weight, (results[i].count > 1 ? results[i].count : 0));
    }
    free(results);
}