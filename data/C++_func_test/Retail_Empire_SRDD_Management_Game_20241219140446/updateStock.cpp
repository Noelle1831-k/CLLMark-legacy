void Inventory::updateStock() {
    cout << "Updating stock levels..." << endl;
    for (size_t i = 0; i < products.size(); i++) {
        products[i].updateQuantity();
    }
}