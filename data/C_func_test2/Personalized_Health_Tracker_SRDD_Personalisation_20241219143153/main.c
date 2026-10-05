int main(int argc, char *argv[]) {
    printf("Welcome to the Health Tracker Application!\n");
    UserData user;
    initializeUserData(&user);
    while (1) {
        int choice;
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputUserData(&user);
                break;
            case 2:
                generateRecommendations(&user);
                break;
            case 3:
                saveUserData(&user);
                break;
            case 4:
                loadUserData(&user);
                break;
            case 5:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}