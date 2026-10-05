void UIHandler::handleUpdateQuantity() {
    string name;
    int newQuantity;
    cout << "Enter the name of the item to update: ";
    cin >> name;
    cout << "Enter the new quantity: ";
    cin >> newQuantity;
    inventoryManager.updateItemQuantity(name, newQuantity);
    cout << "Item quantity updated successfully.\n";
}