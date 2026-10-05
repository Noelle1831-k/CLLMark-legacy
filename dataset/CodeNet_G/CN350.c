void processQueries(int n, char *u, int q, char queries[][20]) {
    for (int i = 0; i < q; i++) {
        if (queries[i][0] == 's') {
            int x, y;
            char z;
            sscanf(queries[i], "set %d %d %c", &x, &y, &z);
            for (int j = x - 1; j <= y - 1; j++) {
                u[j] = z;
            }
        } else if (queries[i][0] == 'c') {
            int a, b, c, d;
            sscanf(queries[i], "comp %d %d %d %d", &a, &b, &c, &d);
            char *s = strndup(u + a - 1, b - a + 1);
            char *t = strndup(u + c - 1, d - c + 1);
            int cmp = strcmp(s, t);
            if (cmp < 0) {
                printf("s\n");
            } else if (cmp > 0) {
                printf("t\n");
            } else {
                printf("e\n");
            }
            free(s);
            free(t);
        }
    }
}