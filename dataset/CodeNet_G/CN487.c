typedef struct {
    int a;
    int b;
} Microbe;
int compare(const void *x, const void *y) {
    Microbe *m1 = (Microbe *)x;
    Microbe *m2 = (Microbe *)y;
    return (m1->b * m2->a) - (m2->b * m1->a);
}
int max_microbes(int N, Microbe microbes[]) {
    qsort(microbes, N, sizeof(Microbe), compare);
    long long sum_a = 0;
    int k;
    for (k = 0; k < N; k++) {
        sum_a += microbes[k].a;
        if (sum_a > (long long)microbes[k].b * (k + 1)) {
            break;
        }
    }
    return k;
}