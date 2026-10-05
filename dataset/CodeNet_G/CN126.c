void check_sudoku(int sudoku[9][9]) {
    int row_count[9][10], col_count[9][10], box_count[3][3][10];
    memset(row_count, 0, sizeof(row_count));
    memset(col_count, 0, sizeof(col_count));
    memset(box_count, 0, sizeof(box_count));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = sudoku[i][j];
            row_count[i][num]++;
            col_count[j][num]++;
            box_count[i / 3][j / 3][num]++;
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = sudoku[i][j];
            if (row_count[i][num] > 1 || col_count[j][num] > 1 || box_count[i / 3][j / 3][num] > 1) {
                printf("*%d", num);
            } else {
                printf(" %d", num);
            }
            if (j < 8) printf(" ");
        }
        printf("\n");
    }
}
