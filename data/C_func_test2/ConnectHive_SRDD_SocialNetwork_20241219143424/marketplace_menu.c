void marketplace_menu() {
    int choice;
    while (1) {
        printf("\n==== Marketplace ====\n");
        printf("1. List an Item\n");
        printf("2. View Listings\n");
        printf("3. Back to Main Menu\n");
        printf("=====================\n");
        printf("Enter your choice: ");
        choice = validate_input();
        switch (choice) {
            case 1:
                list_item();
                break;
            case 2:
                display_all_listings();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}