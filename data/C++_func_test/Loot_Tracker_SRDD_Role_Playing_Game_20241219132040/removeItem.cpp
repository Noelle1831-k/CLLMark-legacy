void InventoryManager::removeItem(const string& name) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == name) {
            categorizedItems[it->getCategory()].erase(
                remove(categorizedItems[it->getCategory()].begin(),
                       categorizedItems[it->getCategory()].end(), *it),
                categorizedItems[it->getCategory()].end());
            items.erase(it);
            break;
        }
    }
}