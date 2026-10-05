char* formatCurrency(double amount) {
    char formatted[50];
    snprintf(formatted, 50, "$%.2f", amount);
    return formatted;
}