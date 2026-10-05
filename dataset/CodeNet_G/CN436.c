void shuffle_cards(int n, int m, int operations[]) {
    int cards[200];
    for (int i = 0; i < 2 * n; i++) {
        cards[i] = i + 1;
    }
    for (int op = 0; op < m; op++) {
        int k = operations[op];
        if (k == 0) {
            int temp[200];
            int index = 0;
            for (int i = 0; i < n; i++) {
                temp[index++] = cards[i];
                temp[index++] = cards[i + n];
            }
            for (int i = 0; i < 2 * n; i++) {
                cards[i] = temp[i];
            }
        } else {
            int temp[200];
            for (int i = 0; i < 2 * n; i++) {
                int new_index = (i < 2 * n - k) ? i + k : i + k - 2 * n;
                temp[new_index] = cards[i];
            }
            for (int i = 0; i < 2 * n; i++) {
                cards[i] = temp[i];
            }
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        printf("%d\n", cards[i]);
    }
}