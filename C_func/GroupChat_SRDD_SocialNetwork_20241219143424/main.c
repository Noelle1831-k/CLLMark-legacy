int main() {
    int choice;
    printf("Welcome to GroupChat: A Social Networking Application\n");
    while (1) {
        displayMainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                handleUserRegistration();
                break;
            case 2:
                handleUserLogin();
                break;
            case 3:
                printf("Exiting GroupChat. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}