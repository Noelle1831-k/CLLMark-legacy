void InventoryManager::addItem(const string &name, int quantity) {
    inventory.push_back(InventoryItem(name, quantity));
    cout << "Added " << quantity << " of " << name << " to inventory." << endl;
}