void CategoryManager::viewCategories() {
    cout << "Categories:\n";
    for (size_t i = 0; i < categories.size(); i++) {
        cout << "- " << categories[i] << endl;
    }
}