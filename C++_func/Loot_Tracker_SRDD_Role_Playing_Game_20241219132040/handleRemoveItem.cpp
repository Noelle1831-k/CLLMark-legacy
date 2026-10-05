void UIHandler::handleRemoveItem() {
    string name;
    cout << "Enter the name of the item to remove: ";
    cin >> name;
    inventoryManager.removeItem(name);
    cout << "Item removed successfully.\n";
}