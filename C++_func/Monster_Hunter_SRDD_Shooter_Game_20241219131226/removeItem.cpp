void Inventory::removeItem(string item) {
    auto it = find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
        cout << "Item '" << item << "' removed from inventory!" << endl;
    } else {
        cout << "Item '" << item << "' not found in inventory!" << endl;
    }
}