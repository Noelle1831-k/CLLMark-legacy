int main() {
    int choice;
    double income, expense;
    char category[50];
    char buffer[100];
    initializeExpenseManager();
    initializeReportGenerator();
    while (1) {
        displayMenu();
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter income amount: ");
                fgets(buffer, sizeof(buffer), stdin);
                if (sscanf(buffer, "%lf", &income) == 1 && income > 0) {
                    addIncome(income);
                } else {
                    printf("Invalid income amount. Please enter a positive number.\n");
                }
                break;
            case 2:
                printf("Enter expense amount: ");
                fgets(buffer, sizeof(buffer), stdin);
                if (sscanf(buffer, "%lf", &expense) == 1 && expense > 0) {
                    printf("Enter category: ");
                    fgets(category, sizeof(category), stdin);
                    category[strcspn(category, "\n")] = 0; 
                    if (strlen(category) > 0) {
                        addExpense(expense, category);
                    } else {
                        printf("Invalid category. Please enter a valid category.\n");
                    }
                } else {
                    printf("Invalid expense amount. Please enter a positive number.\n");
                }
                break;
            case 3:
                generateReport();
                break;
            case 4:
                clearScreen();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}