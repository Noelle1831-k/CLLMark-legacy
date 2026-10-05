double calculate_maturity_amount(int principal, int rate, int years, int type) {
    double amount;
    if (type == 1) {
        amount = principal * (1 + (rate / 100.0) * years);
    } else {
        amount = principal * pow((1 + rate / 100.0), years);
    }
    return amount;
}
void find_best_bank() {
    int n, y;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &y);
        int best_bank = -1;
        double max_amount = -1;
        for (int i = 0; i < n; ++i) {
            int bank_number, rate, type;
            scanf("%d %d %d", &bank_number, &rate, &type);
            double amount = calculate_maturity_amount(1, rate, y, type);
            if (amount > max_amount) {
                max_amount = amount;
                best_bank = bank_number;
            }
        }
        printf("%d\n", best_bank);
    }
}