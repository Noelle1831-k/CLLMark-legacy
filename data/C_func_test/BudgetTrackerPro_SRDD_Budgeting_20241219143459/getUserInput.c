void getUserInput() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            addIncome();  
            break;
        case 2:
            addExpense();  
            break;
        case 3:
            setBudgetGoals();  
            break;
        case 4:
            showBudgetBreakdown();  
            break;
        case 5:
            saveData();  
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}