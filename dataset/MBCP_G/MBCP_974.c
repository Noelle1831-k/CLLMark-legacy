int minSumPath(int **triangle, int n) {
    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col <= row; col++) {
            triangle[row][col] += (triangle[row + 1][col] < triangle[row + 1][col + 1]) ? triangle[row + 1][col] : triangle[row + 1][col + 1];
        }
    }
    return triangle[0][0];
}