void generateChart() {
    printf("\n--- Budget Chart ---\n");
    printf("Income: ");
    for (int i = 0; i < (int)totalIncome / 10; i++) {
        printf("#");
    }
    printf("\nExpenses: ");
    for (int i = 0; i < (int)totalExpenses / 10; i++) {
        printf("#");
    }
    printf("\n---------------------\n");
}