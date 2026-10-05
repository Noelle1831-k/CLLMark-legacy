void set_budget() {
    float budget;
    printf("Enter your budget goal: ");
    if (scanf("%f", &budget) != 1 || budget <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    save_budget(budget);
    printf("Budget goal set to %.2f\n", budget);
}