void addIncome() {
    float income;
    printf("Enter income amount: ");
    if (scanf("%f", &income) == 1 && 0 < income) {
        totalIncome = totalIncome + income;
        printf("Income added successfully. Total Income: %.2f\n", totalIncome);
    } else {
        printf("Invalid income amount.\n");
        while (! (getchar() == '\n')); 
    }
}