int field[10][10];
int signs[10][10];
int memo[15][2];
int X, Y, n;
int verify(int purchaser, int count, int si, int sj, int width, int height) {
    int k = 0;
    for (int i = si; i < si + width; ++i) {
        for (int j = sj; j < sj + height; ++j) {
            if (field[i][j] == 0) {
                if (signs[i][j] && signs[i][j] != purchaser) return 0;
                k++;
            }
        }
    }
    return k == count;
}
int fill(int purchaser, int count, int si, int sj, int width, int height) {
    int k = 0;
    for (int i = si; i < si + width; ++i) {
        for (int j = sj; j < sj + height; ++j) {
            if (field[i][j] == 0) {
                field[i][j] = purchaser;
                k++;
            }
        }
    }
    return k;
}
void rectify() {
    int matched = 1;
    while (matched) {
        matched = 0;
        for (int p = 0; p < n; ++p) {
            int purchaser = memo[p][0];
            int count = memo[p][1];
            for (int si = 0; si < X; ++si) {
                for (int sj = 0; sj < Y; ++sj) {
                    if (field[si][sj] == 0 && (!signs[si][sj] || signs[si][sj] == purchaser)) {
                        for (int width = 1; si + width <= X; ++width) {
                            int area = 0;
                            for (int k = 0; k < width; ++k) {
                                if (field[si + k][sj] != 0 && field[si + k][sj] != purchaser) break;
                                area++;
                            }
                            if (area != width) break;
                            for (int height = 1; sj + height <= Y && width * height <= count; ++height) {
                                if (verify(purchaser, count, si, sj, width, height)) {
                                    int filled = fill(purchaser, count, si, sj, width, height);
                                    if (filled == count) {
                                        matched = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void output() {
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            if (j > 0) printf(" ");
            printf("%d", field[i][j]);
        }
        printf("\n");
    }
}
int process() {
    rectify();
    int found_unfilled = 0;
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            if (field[i][j] == 0) {
                found_unfilled = 1;
                break;
            }
        }
    }
    if (found_unfilled) {
        printf("NA\n");
        return 0;
    }
    output();
    return 1;
}