void frequency_operation(int n, int s[], int p[], int *operations) {
    int c[12], tmp[12];
    int operation_count = 0;
    while (1) {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (s[i] == s[j]) {
                    count++;
                }
            }
            c[i] = count;
        }
        int is_fixed_point = 1;
        for (int i = 0; i < n; ++i) {
            if (c[i] != p[i]) {
                is_fixed_point = 0;
                break;
            }
        }
        memcpy(p, c, n * sizeof(int));
        if (is_fixed_point) {
            break;
        }
        memcpy(tmp, s, n * sizeof(int));
        memcpy(s, p, n * sizeof(int));
        operation_count++;
    }
    *operations = operation_count;
}
