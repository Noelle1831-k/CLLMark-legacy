int calculate_average_shopping_amount(int n, int* amounts) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += amounts[i];
    }
    return (int)(total / n);
}