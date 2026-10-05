int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
int isPairable(const char *a, const char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    if (abs(lenA - lenB) != 1) return 0;
    int diff = 0;
    int i = 0, j = 0;
    while (i < lenA && j < lenB) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            if (diff) return 0;
            diff = 1;
            if (lenA < lenB) j++;
            else i++;
        }
    }
    return 1;
}
int maxPairs(char **names, int N) {
    int paired[N];
    memset(paired, 0, sizeof(paired));
    qsort(names, N, sizeof(char *), compare);
    int pairs = 0;
    for (int i = 0; i < N; i++) {
        if (paired[i]) continue;
        for (int j = i + 1; j < N; j++) {
            if (!paired[j] && isPairable(names[i], names[j])) {
                paired[i] = paired[j] = 1;
                pairs++;
                break;
            }
        }
    }
    return pairs;
}