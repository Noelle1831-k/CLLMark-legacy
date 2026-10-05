#define MAX_CHARS 256
void transformDataSets() {
    char table[MAX_CHARS];
    memset(table, 0, sizeof(table));
    while(1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; ++i) {
            char src, dest;
            scanf(" %c %c", &src, &dest);
            table[(unsigned char)src] = dest;
        }
        int m;
        scanf("%d", &m);
        char result[m + 1];
        for (int i = 0; i < m; ++i) {
            char data;
            scanf(" %c", &data);
            if (table[(unsigned char)data])
                result[i] = table[(unsigned char)data];
            else
                result[i] = data;
        }
        result[m] = '\0';
        printf("%s\n", result);
        memset(table, 0, sizeof(table));
    }
}