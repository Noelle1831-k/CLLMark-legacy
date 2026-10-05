void discussion_management() {
    int choice;
    printf("Discussion Management\n");
    printf("1. Create Discussion\n");
    printf("2. Post Comment\n");
    printf("3. Delete Comment\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            create_discussion();
            break;
        case 2:
            post_comment();
            break;
        case 3:
            delete_comment();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}