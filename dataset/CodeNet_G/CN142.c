void calculate_remainders(int n) {
    int squared_remainders[10000];
    int differences[5001] = {0};
    int max_difference = (n - 1) / 2;
    for (int i = 1; i < n; i++) {
        squared_remainders[i] = (i * i) % n;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = squared_remainders[i] - squared_remainders[j];
            if (diff < 0) {
                diff += n;
            }
            if (diff > max_difference) {
                diff = n - diff;
            }
            differences[diff]++;
        }
    }
    for (int i = 1; i <= max_difference; i++) {
        printf("%d ", differences[i]);
    }
    printf("\n");
}
