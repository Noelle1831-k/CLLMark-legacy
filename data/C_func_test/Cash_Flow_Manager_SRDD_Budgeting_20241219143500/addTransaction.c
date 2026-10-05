void addTransaction() {
    if (transactionCount >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }
    Transaction t;
    printf("Enter description: ");
    fgets(t.description, sizeof(t.description), stdin);
    t.description[strcspn(t.description, "\n")] = '\0';
    printf("Enter amount: ");
    scanf("%lf", &t.amount);
    getchar(); 
    printf("Enter date (YYYY-MM-DD): ");
    fgets(t.date, sizeof(t.date), stdin);
    t.date[strcspn(t.date, "\n")] = '\0';
    if (!validateDate(t.date)) {
        printf("Invalid date format. Please use YYYY-MM-DD.\n");
        return;
    }
    printf("Enter type (income/expense): ");
    fgets(t.type, sizeof(t.type), stdin);
    t.type[strcspn(t.type, "\n")] = '\0';
    transactions[transactionCount++] = t;
    printf("Transaction added successfully.\n");
}