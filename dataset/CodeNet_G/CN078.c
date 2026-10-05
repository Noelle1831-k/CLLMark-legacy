void generateMagicSquare(int n) {
    int magicSquare[15][15] = {0};
    int num = 1;
    int i = n / 2;
    int j = n / 2 + 1;
    magicSquare[i][j] = num++;
    while (num <= n * n) {
        int newI = i + 1;
        int newJ = j + 1;
        if (newI == n) newI = 0;
        if (newJ == n) newJ = 0;
        if (magicSquare[newI][newJ] != 0) {
            newI = i;
            newJ = j - 1;
            if (newJ < 0) newJ = n - 1;
        }
        magicSquare[newI][newJ] = num++;
        i = newI;
        j = newJ;
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf("%4d", magicSquare[x][y]);
        }
        printf("\n");
    }
}
