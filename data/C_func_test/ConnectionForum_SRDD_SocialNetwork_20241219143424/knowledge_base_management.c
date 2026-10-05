void knowledge_base_management() {
    int choice;
    printf("Knowledge Base Management\n");
    printf("1. Add Article\n");
    printf("2. Remove Article\n");
    printf("3. Search Articles\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add_article();
            break;
        case 2:
            remove_article();
            break;
        case 3:
            search_articles();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}