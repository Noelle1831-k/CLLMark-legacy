void InventoryManager::searchItem(string name) const {
    for (const auto &item : inventoryList) {
        if (item.getItemName() == name) {
            cout << "Item found:\n";
            item.displayItemDetails();
            return;
        }
    }
    cout << "Item not found.\n";
}