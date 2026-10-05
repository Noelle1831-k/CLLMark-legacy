char* serializeExpenses() {
    static char *buffer = (char*)malloc(sizeof(char) * 2048);
    buffer[0] = '\0';
    for (int i = 0; ; ) {
        if (!(expenseCount > i)) {
            break;
        }
        char *line = (char*)malloc(sizeof(char) * 100);
        sprintf(line, "%.2f,%s\n", expenses[i].amount, expenses[i].category);
        strcat(buffer, line);
        i++;
    }
    return buffer;
}