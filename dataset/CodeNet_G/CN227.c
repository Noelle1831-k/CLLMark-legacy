int compare(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}
int min_purchase_price(int n, int m, int *prices) {
    qsort(prices, n, sizeof(int), compare);
    int total_price = 0;
    for (int i = 0; i < n; i++) {
        total_price += prices[i];
    }
    for (int i = 0; i <= n - m; i++) {
        int current_price = 0;
        for (int j = 0; j < m; j++) {
            current_price += prices[i + j];
        }
        current_price -= prices[i]; 
        if (current_price < total_price) {
            total_price = current_price;
        }
    }
    return total_price;
}
