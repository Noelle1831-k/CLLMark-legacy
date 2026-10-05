void handleGroupChatOptions(const char* username) {
    int choice;
    while (1) {
        printf("\n===== Group Chat Options =====\n");
        printf("1. Create Group\n");
        printf("2. Join Group\n");
        printf("3. View Messages\n");
        printf("4. Send Message\n");
        printf("5. Logout\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createGroup(username);
                break;
            case 2:
                joinGroup(username);
                break;
            case 3:
                displayMessages(username);
                break;
            case 4:
                sendMessage(username);
                break;
            case 5:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}