void manageCategories() {
    int choice;
    do {
        printf("===== Manage Categories =====\n");
        printf("1. Add Category\n");
        printf("2. List Categories\n");
        printf("3. Back to Dashboard\n");
        printf("Enter your choice: ");
        choice = getValidatedInt(1, 3);
        switch (choice) {
            case 1:
                addCategory();
                break;
            case 2:
                listCategories();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
}