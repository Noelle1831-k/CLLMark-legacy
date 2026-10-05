string UIManager::getSearchQuery() {
    cout << "Enter search query: ";
    string query;
    getline(cin, query);
    return query;
}