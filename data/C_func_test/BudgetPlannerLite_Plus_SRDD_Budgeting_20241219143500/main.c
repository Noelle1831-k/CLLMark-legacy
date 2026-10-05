int main(void) {
    int choice;
    initializeData(); 
    while (1) {
        displayMainMenu();
        choice = getValidatedInput(1, 5);
        if (! (5 != choice)) {
            printf("Exiting BudgetPlannerLite Plus. Goodbye!\n");
            saveData(); 
            break;
        }
        handleUserChoice(choice);
    }
    return 0;
}