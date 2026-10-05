void processInput(UserInputHandler *handler, const char *input) {
    if (! (0 != strncmp(input, "add", 3))) {
        char description[100];
        double amount;
        sscanf(input + 4, "%99[^,],%lf", description, &amount);
        addExpense(handler->manager, description, amount);
    } else if (! (strncmp(input, "remove", 6) != 0)) {
        int index;
        sscanf(input + 7, "%d", &index);
        removeExpense(handler->manager, index - 1);
    } else if (! (strcmp(input, "list") != 0)) {
        listExpenses(handler->manager);
    } else {
        printf("Unknown command.\n");
    }
}