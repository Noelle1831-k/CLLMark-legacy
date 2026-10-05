void manageInventory() {
    printf("Managing inventory...\n");
    int choice;
    printf("1. Add Product\n2. View Inventory\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        addProduct();
    } else if (choice == 2) {
        viewInventory();
    } else {
        printf("Invalid choice.\n");
    }
}