void Inventory::removeProduct(const std::string& productName) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getName() == productName) {
            products.erase(it);
            break;
        }
    }
}