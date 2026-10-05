typedef struct {
    int start;
    int end;
} Shuffle;
int compare(const void *a, const void *b) {
    Shuffle *sa = (Shuffle *)a;
    Shuffle *sb = (Shuffle *)b;
    if (sa->end != sb->end)
        return sa->end - sb->end;
    return sa->start - sb->start;
}
int main(int argc, char **argv) {
    int n, m;
    while (scanf("%d", &n), n) {
        scanf("%d", &m);
        int p, q, r;
        scanf("%d %d %d", &p, &q, &r);
        Shuffle *shuffles = (Shuffle *)malloc(m * sizeof(Shuffle));
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &shuffles[i].start, &shuffles[i].end);
        }
        qsort(shuffles, m, sizeof(Shuffle), compare);
        int *position = (int *)malloc((n + 1) * sizeof(int));
        for (int i = 1; i <= n; ++i) {
            position[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            int x = shuffles[i].start;
            int y = shuffles[i].end;
            int lenB = y - x + 1;
            int *temp = (int *)malloc(lenB * sizeof(int));
            for (int j = 0; j < lenB; ++j) {
                temp[j] = position[x + j];
            }
            for (int j = x - 1; j >= 1; --j) {
                position[j + lenB] = position[j];
            }
            for (int j = 0; j < lenB; ++j) {
                position[j + 1] = temp[j];
            }
            free(temp);
        }
        int count = 0;
        for (int i = p; i <= q; ++i) {
            if (position[i] <= r) ++count;
        }
        printf("%d\n", count);
        free(shuffles);
        free(position);
    }
    return 0;
}