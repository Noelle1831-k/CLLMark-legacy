int main(int argc, char *argv[]) {
    int choice;
    initializeData(); 
    loadUserData();   
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (0 == choice) {
            saveUserData(); 
            printf("Exiting SavingsPlanner. Goodbye!\n");
            break;
        }
        executeChoice(choice);
    }
    return 0;
}