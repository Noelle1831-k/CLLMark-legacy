void UIHandler::handleAddItem() {
    string name, category, expirationDate, description;
    int quantity;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter category: ";
    cin >> category;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter expiration date: ";
    cin >> expirationDate;
    cout << "Enter description: ";
    cin.ignore();
    getline(cin, description);
    Item item(name, category, quantity, expirationDate, description);
    inventoryManager.addItem(item);
    cout << "Item added successfully.\n";
}