void UIHandler::handleViewItems() {
    vector<Item> items = inventoryManager.getItems();
    for (const auto& item : items) {
        cout << "Name: " << item.getName() << ", Category: " << item.getCategory()
             << ", Quantity: " << item.getQuantity() << ", Expiration Date: " << item.getExpirationDate()
             << ", Description: " << item.getDescription() << endl;
    }
}