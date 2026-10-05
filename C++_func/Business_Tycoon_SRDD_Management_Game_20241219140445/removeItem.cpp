void InventoryManager::removeItem(const string &name) {
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == name) {
            inventory.erase(inventory.begin() + i);
            cout << "Removed " << name << " from inventory." << endl;
            return;
        }
    }
    cout << "Item " << name << " not found in inventory." << endl;
}