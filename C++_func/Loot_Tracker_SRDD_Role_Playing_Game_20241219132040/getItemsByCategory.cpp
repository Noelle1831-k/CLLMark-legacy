vector<Item> InventoryManager::getItemsByCategory(const string& category) const {
    auto it = categorizedItems.find(category);
    if (it != categorizedItems.end()) {
        return it->second;
    }
    return {};
}