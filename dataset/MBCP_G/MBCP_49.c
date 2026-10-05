void specifiedElement(int nums[][4], int numRows, int numCols, int n, int result[]) {
    for (int i = 0; i < numRows; i++) {
        if (n < numCols) {
            result[i] = nums[i][n];
        }
    }
}