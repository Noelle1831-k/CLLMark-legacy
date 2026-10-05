int main() {
    int choice;
    initializeDatabase(); 
    while (1) {
        displayMenu(); 
        choice = getValidatedIntegerInput(); 
        switch (choice) {
            case 1:
                createUserProfile(); 
                break;
            case 2:
                displayAllProfiles(); 
                break;
            case 3:
                findMatches(); 
                break;
            case 4:
                printf("Thank you for using LoveConnect. Goodbye!\n");
                exit(0); 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}