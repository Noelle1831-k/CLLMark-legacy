void InventoryItem::displayItemDetails() const {
    cout << left << setw(15) << itemID
         << setw(20) << itemName
         << setw(10) << quantity
         << setw(10) << pricePerUnit << endl;
}