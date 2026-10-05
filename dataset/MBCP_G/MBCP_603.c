void getLudic(int n, int *result, int *size) {
    int *ludic = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        ludic[i] = i;
    }
    int index = 0;
    for (int i = 2; i <= n; i++) {
        if (ludic[i] != 0) {
            result[index++] = ludic[i];
            int count = 0;
            for (int j = i; j <= n; j++) {
                if (ludic[j] != 0) {
                    count++;
                }
                if (count % ludic[i] == 0) {
                    ludic[j] = 0;
                }
            }
        }
    }
    *size = index;
    free(ludic);
}
