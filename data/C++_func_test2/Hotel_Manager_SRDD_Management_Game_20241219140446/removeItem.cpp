void Inventory::removeItem(string item, int quantity) {
    if (stock[item] >= quantity) {
        stock[item] -= quantity;
        cout << "Removed " << quantity << " of " << item << " from inventory." << endl;
    } else {
        cout << "Not enough stock of " << item << " to remove." << endl;
    }
}