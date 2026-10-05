void networking_management() {
    int choice;
    printf("Networking Management\n");
    printf("1. Send Message\n");
    printf("2. Receive Message\n");
    printf("3. Connect with User\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            send_message();
            break;
        case 2:
            receive_message();
            break;
        case 3:
            connect_with_user();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}