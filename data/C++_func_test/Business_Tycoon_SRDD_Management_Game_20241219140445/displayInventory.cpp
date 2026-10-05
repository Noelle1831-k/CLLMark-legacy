void InventoryManager::displayInventory() {
    cout << "Inventory:" << endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << inventory[i].name << " - " << inventory[i].quantity << endl;
    }
}