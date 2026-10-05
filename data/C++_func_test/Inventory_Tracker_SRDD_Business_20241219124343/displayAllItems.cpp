void InventoryManager::displayAllItems() const {
    cout << left << setw(15) << "Item ID"
         << setw(20) << "Item Name"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << endl;
    for (const auto &item : inventoryList) {
        item.displayItemDetails();
    }
}