void input_expense() {
    char category[50];
    float amount;
    char description[100];
    printf("Enter category (e.g., Food, Travel): ");
    scanf("%s", category);
    printf("Enter amount: ");
    if (scanf("%f", &amount) != 1) {
        printf("Invalid input. Please enter a valid number for the amount.\n");
        while (getchar() != '\n'); 
        return;
    }
    printf("Enter description (optional): ");
    getchar(); 
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = '\0'; 
    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
        return;
    }
    add_expense(category, amount, description);
    printf("Expense added successfully.\n");
}