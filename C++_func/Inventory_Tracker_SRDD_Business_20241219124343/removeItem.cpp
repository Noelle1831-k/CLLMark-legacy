void InventoryManager::removeItem(string name) {
    for (auto it = inventoryList.begin(); it != inventoryList.end(); ++it) {
        if (it->getItemName() == name) {
            inventoryList.erase(it);
            cout << "Item removed successfully.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}