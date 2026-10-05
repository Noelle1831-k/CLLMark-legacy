double calculateTotalExpenses() {
    double total = 0.0;
    for (int i = 0; i < expenseIndex; i++) {
        total += expenseList[i];  
    }
    return total;
}