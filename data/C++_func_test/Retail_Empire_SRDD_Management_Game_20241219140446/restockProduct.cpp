void Inventory::restockProduct(const std::string& productName, int quantity) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getName() == productName) {
            products[i].updateQuantity(quantity);
            break;
        }
    }
}