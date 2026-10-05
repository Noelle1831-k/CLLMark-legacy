void CategoryManager::addCategory() {
    string category;
    cout << "Enter new category name: ";
    cin >> category;
    categories.push_back(category);
    cout << "Category added successfully.\n";
}