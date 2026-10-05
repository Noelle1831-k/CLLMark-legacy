void loadData() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        printf("Error loading data.\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Transaction t;
        sscanf(line, "%10[^|]|%99[^|]|%lf|%9s", t.date, t.description, &t.amount, t.type);
        addTransactionFromFile(t);
    }
    fclose(file);
    printf("Data loaded successfully.\n");
}