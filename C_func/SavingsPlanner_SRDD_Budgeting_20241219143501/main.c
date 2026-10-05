int main() {
    int choice;
    initializeData(); 
    loadUserData();   
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 0) {
            saveUserData(); 
            printf("Exiting SavingsPlanner. Goodbye!\n");
            break;
        }
        executeChoice(choice);
    }
    return 0;
}