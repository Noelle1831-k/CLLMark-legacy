int main(int argc, char *argv[]) {
    int choice;
    initializeData(); 
    while (1) {
        displayMainMenu();
        choice = getValidatedInput(1, 5);
        if (choice == 5) {
            printf("Exiting BudgetPlannerLite Plus. Goodbye!\n");
            saveData(); 
            break;
        }
        handleUserChoice(choice);
    }
    return 0;
}