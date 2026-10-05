char* serializeExpenses() {
    static char buffer[2048];
    buffer[0] = '\0';
    for (int i = 0; i < expenseCount; i++) {
        char line[100];
        sprintf(line, "%.2f,%s\n", expenses[i].amount, expenses[i].category);
        strcat(buffer, line);
    }
    return buffer;
}