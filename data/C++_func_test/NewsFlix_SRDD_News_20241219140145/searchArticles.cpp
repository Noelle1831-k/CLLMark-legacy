void SearchEngine::searchArticles() {
    string query;
    printf("Enter search query: ");
    cin.ignore();
    getline(cin, query);
    performSearch(query);
}