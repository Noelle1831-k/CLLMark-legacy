int countInversions(int *a, int n, int dir) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((dir == 1 && a[i] > a[j]) || (dir == 2 && a[i] < a[j])) {
                count++;
            }
        }
    }
    return count;
}
bool solve(int *a, int n) {
    int incInversions = countInversions(a, n, 1);
    int decInversions = countInversions(a, n, 2);
    return incInversions == decInversions;
}