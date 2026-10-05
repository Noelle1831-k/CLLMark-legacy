int calculate_missing_price(int total_sum, int prices[], int n) {
    int known_sum = 0;
    for (int i = 0; i < n; i++) {
        known_sum += prices[i];
    }
    return total_sum - known_sum;
}