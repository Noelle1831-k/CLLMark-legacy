void InventoryManager::addItem(string name, int quantity, double price) {
    string id = "ITEM" + to_string(inventoryList.size() + 1);
    InventoryItem newItem(id, name, quantity, price);
    inventoryList.push_back(newItem);
    cout << "Item added successfully.\n";
}