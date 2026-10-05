double calculateExpenses(double expenses[]) {
    double total = 0;
    for (int i = 0; i < 5; i++) {
        total += expenses[i];
    }
    return total;
}