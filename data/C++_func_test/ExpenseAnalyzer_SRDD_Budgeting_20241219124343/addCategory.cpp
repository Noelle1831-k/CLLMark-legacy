void CategoryManager::addCategory() {
    string category;
    printf("Enter new category name: ");
    cin >> category;
    categories.push_back(category);
    printf("Category added successfully.\n");
}