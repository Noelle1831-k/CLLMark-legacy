int isCheckered(int w, int h, int grid[][1000]) {
    int rowCheckeredPattern1 = grid[0][0];
    int rowCheckeredPattern2 = 1 - grid[0][0];
    int columnPattern[2][1000];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] != ((i + j) % 2 == 0 ? rowCheckeredPattern1 : rowCheckeredPattern2)) {
                return 0;
            }
        }
    }
    for (int j = 0; j < w; j++) {
        columnPattern[0][j] = grid[0][j];
        columnPattern[1][j] = 1 - grid[0][j];
    }
    for (int i = 1; i < h; i++) {
        int rowPatternType = (grid[i][0] == columnPattern[0][0]) ? 0 : (grid[i][0] == columnPattern[1][0]) ? 1 : -1;
        if (rowPatternType == -1) return 0;
        for (int j = 1; j < w; j++) {
            if (grid[i][j] != columnPattern[rowPatternType][j]) {
                return 0;
            }
        }
    }
    return 1;
}