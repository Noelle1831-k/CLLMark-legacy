#define MAX_ROWS 100
int max(int a, int b) {
    return (a > b) ? a : b;
}
int maxPathSum(int diamond[MAX_ROWS][MAX_ROWS], int n) {
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            diamond[i][j] += max(diamond[i+1][j], diamond[i+1][j+1]);
        }
    }
    return diamond[0][0];
}