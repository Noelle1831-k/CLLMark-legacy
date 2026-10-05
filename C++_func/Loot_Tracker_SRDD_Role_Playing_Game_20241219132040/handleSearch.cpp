void UIHandler::handleSearch() {
    string query;
    cout << "Enter search query: ";
    cin >> query;
    vector<Item> results = searchEngine.searchItems(inventoryManager.getItems(), query);
    for (const auto& item : results) {
        cout << "Found - Name: " << item.getName() << endl;
    }
}