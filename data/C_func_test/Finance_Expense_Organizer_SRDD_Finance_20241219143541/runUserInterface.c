void runUserInterface(UserInterface *ui) {
    int choice;
    do {
        printf("1. Add Expense\n2. Remove Expense\n3. List Expenses\n4. Add Category\n5. List Categories\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                double amount;
                char category[50], description[100];
                printf("Enter amount: ");
                scanf("%lf", &amount);
                printf("Enter category: ");
                scanf("%s", category);
                printf("Enter description: ");
                scanf("%s", description);
                addExpense(ui->expenseManager, amount, category, description);
                break;
            }
            case 2: {
                int index;
                printf("Enter expense index to remove: ");
                scanf("%d", &index);
                removeExpense(ui->expenseManager, index);
                break;
            }
            case 3:
                listExpenses(ui->expenseManager);
                break;
            case 4: {
                char name[50];
                printf("Enter category name: ");
                scanf("%s", name);
                addCategory(ui->categoryManager, name);
                break;
            }
            case 5:
                listCategories(ui->categoryManager);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
}