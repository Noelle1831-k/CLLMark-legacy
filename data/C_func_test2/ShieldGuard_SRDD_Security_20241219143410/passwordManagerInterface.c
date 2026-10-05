void passwordManagerInterface() {
    int choice;
    char *password = (char*)malloc(sizeof(char) * 100);
    while (1) {
        printf("\n--- Password Manager ---\n");
        printf("1. Store Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Back to Dashboard\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter password to store: ");
                scanf("%s", password);
                storePassword(password);
                break;
            case 2:
                retrievePassword();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}