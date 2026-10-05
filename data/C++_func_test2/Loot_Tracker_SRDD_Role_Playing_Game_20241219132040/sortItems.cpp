void InventoryManager::sortItems(const string& criteria) {
    if (criteria == "name") {
        sort(items.begin(), items.end(),
             [](const Item& a, const Item& b) { return a.getName() < b.getName(); });
    } else if (criteria == "category") {
        sort(items.begin(), items.end(),
             [](const Item& a, const Item& b) { return a.getCategory() < b.getCategory(); });
    } else if (criteria == "expiration") {
        sort(items.begin(), items.end(),
             [](const Item& a, const Item& b) { return a.getExpirationDate() < b.getExpirationDate(); });
    }
}