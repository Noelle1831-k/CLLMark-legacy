void deserializeExpenses(const char *data) {
    char *line;
    char buffer[2048];
    strcpy(buffer, data);
    line = strtok(buffer, "\n");
    while (line != NULL) {
        double amount;
        char category[50];
        sscanf(line, "%lf,%49s", &amount, category);
        addExpense(amount, category);
        line = strtok(NULL, "\n");
    }
}