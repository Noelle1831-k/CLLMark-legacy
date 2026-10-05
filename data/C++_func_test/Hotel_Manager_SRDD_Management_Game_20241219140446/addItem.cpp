void Inventory::addItem(string item, int quantity) {
    stock[item] = stock[item] + quantity;
    cout << "Added " << quantity << " of " << item << " to inventory." << endl;
}