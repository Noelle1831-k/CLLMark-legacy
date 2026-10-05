void addToSavings() {
    double amount;
    printf("Enter amount to add to savings: ");
    amount = getValidatedDouble();
    currentSavings += amount;
    printf("Savings updated. Current savings: %.2f\n", currentSavings);
}