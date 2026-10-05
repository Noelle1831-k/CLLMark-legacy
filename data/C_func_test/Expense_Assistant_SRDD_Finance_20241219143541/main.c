int main() {
    int choice;
    loadFromFile(); 
    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 8.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); 
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                categorizeExpense();
                break;
            case 4:
                generateReport();
                break;
            case 5:
                setBudget();
                break;
            case 6:
                checkBudget();
                break;
            case 7:
                visualizeSpending();
                break;
            case 8:
                saveToFile();
                printf("Data saved. Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}