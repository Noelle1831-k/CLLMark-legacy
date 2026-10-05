int noOfTriangle(int n, int k) {
    if (k > n) return -1;
    int totalTriangles = 0;
    for (int row = 0; row < (n - k + 1); ++row) {
        totalTriangles += (n - k - row + 1);
    }
    return totalTriangles;
}