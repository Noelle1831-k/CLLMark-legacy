char* formatCurrency(double amount) {
    char *formatted = (char *)malloc(50);
    snprintf(formatted, 50, "$%.2f", amount);
    return formatted;
}