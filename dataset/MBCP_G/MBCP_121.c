bool checkTriplet(int a[], int n, int sum, int count) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] + a[k] == sum) {
                    return true;
                }
            }
        }
    }
    return false;
}