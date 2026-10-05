void InventoryManager::updateItemQuantity(const string& name, int quantity) {
    for (auto& item : items) {
        if (item.getName() == name) {
            item.setQuantity(quantity);
            break;
        }
    }
}