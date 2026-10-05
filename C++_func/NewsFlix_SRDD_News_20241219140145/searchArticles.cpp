void SearchEngine::searchArticles() {
    string query;
    cout << "Enter search query: ";
    cin.ignore();
    getline(cin, query);
    performSearch(query);
}