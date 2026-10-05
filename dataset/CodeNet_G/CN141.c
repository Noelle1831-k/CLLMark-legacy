void printSpiral(int n) {
    char spiral[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            spiral[i][j] = ' ';
    int x = 0, y = n - 1;
    while (n > 0) {
        if (n == 1) {
            spiral[y][x] = '#';
            break;
        }
        for (int i = 0; i < n - 1; i++) spiral[y][x + i] = '#';
        for (int i = 0; i < n - 1; i++) spiral[y - i][x + n - 1] = '#';
        for (int i = 0; i < n - 1; i++) spiral[y - n + 1][x + n - 1 - i] = '#';
        for (int i = 0; i < n - 1; i++) spiral[y - n + 1 + i][x] = '#';
        x += 2;
        y -= 2;
        n -= 4;
    }
    for (int i = 0; i < y + 3; i++) {
        for (int j = 0; j < x - 2; j++) {
            printf("%c", spiral[i][j]);
        }
        printf("\n");
    }
}
