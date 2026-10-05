void InventoryManager::addItem(const Item& item) {
    items.push_back(item);
    categorizedItems[item.getCategory()].push_back(item);
}