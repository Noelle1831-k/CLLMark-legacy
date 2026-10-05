void Inventory::showProducts() const {
    cout << "Current products in inventory:" << endl;
    for (size_t i = 0; i < products.size(); i++) {
        cout << products[i].getName() << " - " << products[i].getQuantity() << " units" << endl;
    }
}