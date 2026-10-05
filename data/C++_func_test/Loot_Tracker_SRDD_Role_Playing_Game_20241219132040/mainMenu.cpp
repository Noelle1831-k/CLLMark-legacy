void UIHandler::mainMenu() {
    int choice;
    do {
        cout << "1. Add Item\n2. Remove Item\n3. View Items\n4. Search\n5. Notifications\n6. Update Item Quantity\n7. Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                handleAddItem();
                break;
            case 2:
                handleRemoveItem();
                break;
            case 3:
                handleViewItems();
                break;
            case 4:
                handleSearch();
                break;
            case 5:
                handleNotifications();
                break;
            case 6:
                handleUpdateQuantity();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 7);
}