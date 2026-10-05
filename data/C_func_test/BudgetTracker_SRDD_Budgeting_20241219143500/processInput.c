void processInput() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a valid choice.\n");
        while (getchar() != '\n'); 
        waitForInput();
        return;
    }
    switch (choice) {
        case 1: {
            float income;
            printf("Enter income amount: ");
            if (1 != scanf("%f", &income)) {
                printf("Invalid income value. Please try again.\n");
                waitForInput();
                return;
            }
            addIncome(income);
            break;
        }
        case 2: {
            float expense;
            char *category = (char*)malloc(sizeof(char) * 50);
            printf("Enter expense amount: ");
            if (1 != scanf("%f", &expense)) {
                printf("Invalid expense value. Please try again.\n");
                waitForInput();
                return;
            }
            printf("Enter expense category: ");
            scanf("%s", category);
            addExpense(expense, category);
            break;
        }
        case 3: {
            editExpense();
            break;
        }
        case 4: {
            deleteExpense();
            break;
        }
        case 5:
            viewSummary();
            waitForInput();
            break;
        case 6:
            generateReport();
            waitForInput();
            break;
        case 7:
            saveData();
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
            waitForInput();
    }
}