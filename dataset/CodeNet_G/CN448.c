int max_shipable_senbei(int R, int C, int grid[10][10000]) {
    int max_shipable = 0;
    for (int row_mask = 0; row_mask < (1 << R); ++row_mask) {
        int temp_grid[10][10000];
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                temp_grid[i][j] = grid[i][j];
        for (int i = 0; i < R; ++i) {
            if (row_mask & (1 << i)) {
                for (int j = 0; j < C; ++j) {
                    temp_grid[i][j] = 1 - temp_grid[i][j];
                }
            }
        }
        int total_shipable = 0;
        for (int j = 0; j < C; ++j) {
            int count = 0;
            for (int i = 0; i < R; ++i) {
                count += temp_grid[i][j];
            }
            total_shipable += (count > R / 2) ? count : R - count;
        }
        if (total_shipable > max_shipable) {
            max_shipable = total_shipable;
        }
    }
    return max_shipable;
}