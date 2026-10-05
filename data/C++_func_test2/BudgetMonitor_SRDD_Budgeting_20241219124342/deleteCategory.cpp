void CategoryManager::deleteCategory(const std::string& category) {
    auto it = std::find(categories.begin(), categories.end(), category);
    if (it != categories.end()) {
        categories.erase(it);
    }
}