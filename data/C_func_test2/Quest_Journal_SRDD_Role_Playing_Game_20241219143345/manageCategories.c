void manageCategories() {
    int choice;
    do {
        printf("\nCategory Management:\n1. Add Category\n2. Remove Category\n3. List Categories\n4. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCategory();
                break;
            case 2:
                removeCategory();
                break;
            case 3:
                listCategories();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}