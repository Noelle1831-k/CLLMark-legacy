int main() {
    printf("Welcome to BudgetOptimizerLiteEZ!\n");
    printf("Track your income and expenses effectively.\n\n");
    BudgetManager manager = createBudgetManager();
    UserInputHandler userInputHandler = createUserInputHandler(&manager);
    char command[256];
    while (1) {
        printf("\nEnter a command (type 'help' for options, 'exit' to quit): ");
        fgets(command, 256, stdin);
        command[strcspn(command, "\n")] = 0; 
        if (strcmp(command, "exit") == 0) {
            printf("Exiting BudgetOptimizerLiteEZ. Goodbye!\n");
            break;
        }
        handleCommand(&userInputHandler, command);
    }
    return 0;
}