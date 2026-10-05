int main() {
    printf("Welcome to BudgetMaster - Your Financial Assistant\n");
    User user = createUser(); 
    loadDataFromFile(&user);  
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputIncome(&user);
                break;
            case 2:
                inputExpense(&user);
                break;
            case 3:
                setBudgetGoals(&user);
                break;
            case 4:
                generateBudgetReport(&user);
                break;
            case 5:
                displayFinancialTips();
                break;
            case 6:
                saveDataToFile(&user);
                printf("Data saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}