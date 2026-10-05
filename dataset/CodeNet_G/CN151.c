#define MAX_N 255
int grid[MAX_N][MAX_N];
int max(int a, int b) {
    return a > b ? a : b;
}
int longest_consecutive(int n) {
    int max_consecutive = 0;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                count++;
            } else {
                count = 0;
            }
            max_consecutive = max(max_consecutive, count);
        }
    }
    for (int j = 0; j < n; ++j) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] == 1) {
                count++;
            } else {
                count = 0;
            }
            max_consecutive = max(max_consecutive, count);
        }
    }
    for (int d = -(n-1); d <= n-1; ++d) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int j = i + d;
            if (j >= 0 && j < n) {
                if (grid[i][j] == 1) {
                    count++;
                } else {
                    count = 0;
                }
                max_consecutive = max(max_consecutive, count);
            }
        }
    }
    for (int d = 0; d <= 2*(n-1); ++d) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int j = d - i;
            if (j >= 0 && j < n) {
                if (grid[i][j] == 1) {
                    count++;
                } else {
                    count = 0;
                }
                max_consecutive = max(max_consecutive, count);
            }
        }
    }
    return max_consecutive;
}