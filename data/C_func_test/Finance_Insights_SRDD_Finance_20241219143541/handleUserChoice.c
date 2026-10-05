void handleUserChoice() {
    struct Transaction transactions[100];
    int transactionCount = 0;
    int choice = 0;
    while (choice != 5) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Adding a new transaction...\n");
                int id;
                char type[10];
                double amount;
                char date[20];
                printf("Enter Transaction ID: ");
                scanf("%d", &id);
                printf("Enter Transaction Type (income/expense): ");
                scanf("%s", type);
                printf("Enter Transaction Amount: ");
                scanf("%lf", &amount);
                printf("Enter Transaction Date (YYYY-MM-DD): ");
                scanf("%s", date);
                transactions[transactionCount] = *addTransaction(id, type, amount, date);
                transactionCount++;
                printf("Transaction added successfully!\n");
                break;
            }
            case 2: {
                printf("Analyzing transactions...\n");
                analyzeTransactions(transactions, transactionCount);
                break;
            }
            case 3: {
                printf("Generating and displaying report...\n");
                generateReport();
                displayReport();
                break;
            }
            case 4: {
                printf("Generating and displaying charts...\n");
                generateChart();
                displayChart();
                break;
            }
            case 5: {
                printf("Exiting application. Goodbye!\n");
                break;
            }
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}