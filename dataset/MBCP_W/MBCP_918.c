int coinChange(int s[], int m, int n) {
    int *table = (int *)malloc(sizeof(int) * n + 1);
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for (int i = 0; i < m; i++)
        for (int j = s[i]; j <= n; j++)
            table[j] += table[j - s[i]];
    return table[n];
}