int main() {
    ExpenseManager *manager = createExpenseManager();
    UserInputHandler *inputHandler = createUserInputHandler(manager);
    while (1) {
        displayDashboard(manager);
        char *input = getUserInput();
        processInput(inputHandler, input);
        free(input);
    }
    destroyExpenseManager(manager);
    destroyUserInputHandler(inputHandler);
    return 0;
}