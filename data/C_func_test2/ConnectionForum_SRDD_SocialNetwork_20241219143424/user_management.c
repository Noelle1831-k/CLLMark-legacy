void user_management() {
    int choice;
    printf("User Management\n");
    printf("1. Create User\n");
    printf("2. Delete User\n");
    printf("3. Update User Info\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            create_user();
            break;
        case 2:
            delete_user();
            break;
        case 3:
            update_user_info();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}