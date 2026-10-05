void setBudget() {
    printf("Enter your budget: ");
    if (scanf("%lf", &budget) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        clearInputBuffer();
        return;
    }
    printf("Budget set to $%.2f\n", budget);
}