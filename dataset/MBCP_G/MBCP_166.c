int findEvenPair(int a[], int n) {
    int even_count = 0, odd_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    return even_count * odd_count;
}