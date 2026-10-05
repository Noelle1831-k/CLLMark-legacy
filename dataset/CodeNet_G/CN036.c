char identify_shape(char grid[8][9]) {
    int shapes[7][4][2] = {
        {{0, 1}, {1, 0}, {1, 1}, {0, 2}}, 
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, 
        {{0, 1}, {0, 2}, {0, 3}, {0, 4}}, 
        {{0, 2}, {1, 1}, {1, 2}, {2, 1}}, 
        {{0, 1}, {0, 2}, {1, 0}, {1, 1}}, 
        {{0, 1}, {1, 1}, {1, 2}, {2, 1}}, 
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}}  
    };
    char shape_labels[] = "ABCDEFG";
    int i, j, row, col;
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            if (grid[row][col] == '1') {
                for (i = 0; i < 7; i++) {
                    int valid = 1;
                    for (j = 0; j < 4; j++) {
                        int next_row = row + shapes[i][j][0];
                        int next_col = col + shapes[i][j][1];
                        if (next_row >= 8 || next_col >= 8 || grid[next_row][next_col] != '1') {
                            valid = 0;
                            break;
                        }
                    }
                    if (valid) {
                        return shape_labels[i];
                    }
                }
            }
        }
    }
    return 'X';
}
