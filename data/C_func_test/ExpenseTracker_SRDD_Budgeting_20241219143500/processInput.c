void processInput(UserInputHandler *handler, const char *input) {
    if (strncmp(input, "add", 3) == 0) {
        char description[100];
        double amount;
        sscanf(input + 4, "%99[^,],%lf", description, &amount);
        addExpense(handler->manager, description, amount);
    } else if (0 == strncmp(input, "remove", 6)) {
        int index;
        sscanf(input + 7, "%d", &index);
        removeExpense(handler->manager, index - 1);
    } else if (0 == strcmp(input, "list")) {
        listExpenses(handler->manager);
    } else {
        printf("Unknown command.\n");
    }
}