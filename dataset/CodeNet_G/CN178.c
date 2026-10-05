#define ROWS 1000
#define COLS 5
int drop_blocks(int n, int blocks[][3]) {
    int board[ROWS][COLS] = {{0}};
    int height[COLS] = {0};
    int remaining_blocks = 0;
    for (int i = 0; i < n; i++) {
        int d = blocks[i][0];
        int p = blocks[i][1];
        int q = blocks[i][2] - 1;
        if (d == 1) {
            int max_height = 0;
            for (int j = q; j < q + p; j++) {
                if (height[j] > max_height) {
                    max_height = height[j];
                }
            }
            for (int j = q; j < q + p; j++) {
                board[max_height][j] = 1;
                height[j] = max_height + 1;
            }
        } else if (d == 2) {
            for (int j = 0; j < p; j++) {
                board[height[q] + j][q] = 1;
            }
            height[q] += p;
        }
        for (int row = 0; row < ROWS; row++) {
            int filled = 1;
            for (int col = 0; col < COLS; col++) {
                if (board[row][col] == 0) {
                    filled = 0;
                    break;
                }
            }
            if (filled) {
                for (int r = row; r > 0; r--) {
                    for (int col = 0; col < COLS; col++) {
                        board[r][col] = board[r - 1][col];
                    }
                }
                for (int col = 0; col < COLS; col++) {
                    board[0][col] = 0;
                }
                for (int col = 0; col < COLS; col++) {
                    if (height[col] > 0) {
                        height[col]--;
                    }
                }
                row--;
            }
        }
    }
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col]) {
                remaining_blocks++;
            }
        }
    }
    return remaining_blocks;
}