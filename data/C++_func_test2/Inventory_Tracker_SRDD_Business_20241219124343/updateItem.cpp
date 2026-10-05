void InventoryManager::updateItem(string name, int quantity, double price) {
    for (auto &item : inventoryList) {
        if (item.getItemName() == name) {
            item.updateQuantity(quantity);
            item.updatePrice(price);
            cout << "Item updated successfully.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}