int main() {
    initializeDashboard();
    loadUserData();
    int running = 1;
    while (running) {
        printf("1. View Transactions\n");
        printf("2. Add Transaction\n");
        printf("3. Set Budget\n");
        printf("4. View User Profile\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                listTransactions();
                break;
            case 2:
                addTransaction();
                break;
            case 3:
                setBudget();
                break;
            case 4:
                displayUserProfile();
                break;
            case 5:
                saveUserData();
                running = 0;
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}