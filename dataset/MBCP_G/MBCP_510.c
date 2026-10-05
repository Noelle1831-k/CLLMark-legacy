int countProductsLessThanK(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < (1 << n); i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                product *= arr[j];
            }
        }
        if (product < k && product > 1) {
            count++;
        }
    }
    return count;
}