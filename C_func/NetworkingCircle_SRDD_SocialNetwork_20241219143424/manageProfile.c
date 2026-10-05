void manageProfile() {
    if (loggedInUserIndex == -1) {
        printf("No user logged in.\n");
        return;
    }
    int choice;
    while (1) {
        printf("\nProfile Management:\n");
        printf("1. Update Industry\n2. View Connections\n3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char newIndustry[50];
                printf("Enter your new industry: ");
                scanf("%s", newIndustry);
                strcpy(users[loggedInUserIndex].industry, newIndustry);
                printf("Industry updated successfully!\n");
                break;
            }
            case 2:
                displayConnections();
                break;
            case 3:
                printf("Logging out...\n");
                loggedInUserIndex = -1;
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}