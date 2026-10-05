int i, j, s, t, e, L, N, M;
int a[10001] = {0};
int b[10001];
int c[10001];
void compute_salaries(int L, int N, int records[][3], int wages[][10000]) {
    for (i = 0; i < 10001; i++) a[i] = 0;
    for (i = 0; i < N; i++) {
        s = records[i][0];
        t = records[i][1];
        e = records[i][2];
        a[(s-1)*10000 + (t-1)] = e;
    }
    for (i = 0; i < L; i++) {
        for (j = 0; j < 10001; j++) b[j] = 0;
        for (j = 0; j < 10000; j++) {
            b[j] = wages[i][j];
        }
        for (j = 0; j < N; j++) c[j] = 0;
        for (j = 0; j < 10001; j++) {
            if (a[j] > 0) {
                int index = (j / 10000);
                int type = (j % 10000);
                c[index] += a[j] * b[type];
            }
        }
        for (j = 0; j < N; j++) {
            printf("%d", c[j]);
            if (j < N-1) printf(" ");
        }
        printf("\n");
    }
}