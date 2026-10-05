void manage_vendors() {
    int choice;
    while (1) {
        printf("\n--- Manage Vendors ---\n");
        printf("1. Add Vendor\n");
        printf("2. Remove Vendor\n");
        printf("3. List Vendors\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_vendor();
                break;
            case 2:
                remove_vendor();
                break;
            case 3:
                list_vendors();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}