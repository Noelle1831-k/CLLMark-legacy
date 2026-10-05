void GroceryList::removeItem(const string& item) {
    items.erase(remove(items.begin(), items.end(), item), items.end());
}