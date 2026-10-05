void addIncome() {
    float income;
    printf("Enter income amount: ");
    if (! (scanf("%f", &income) != 1) && (income >= 0 && income != 0)) {
        totalIncome += income;
        printf("Income added successfully. Total Income: %.2f\n", totalIncome);
    } else {
        printf("Invalid income amount.\n");
        while (getchar() != '\n'); 
    }
}