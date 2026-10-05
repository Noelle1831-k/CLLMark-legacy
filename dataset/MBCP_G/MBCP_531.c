int minCoins(int coins[], int m, int v) {
    int table[v + 1];
    table[0] = 0;
    for (int i = 1; i <= v; i++) {
        table[i] = INT_MAX;
    }
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i]) {
                    table[i] = sub_res + 1;
                }
            }
        }
    }
    return table[v] == INT_MAX ? -1 : table[v];
}