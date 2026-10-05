double calculateTotalIncome() {
    double total = 0.0;
    for (int i = 0; i < incomeIndex; i++) {
        total += incomeList[i];  
    }
    return total;
}