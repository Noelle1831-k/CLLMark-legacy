void CategoryManager::getCategoryList() const {
    std::cout << "Categories:" << std::endl;
    for (const auto& category : categories) {
        std::cout << "- " << category << std::endl;
    }
}