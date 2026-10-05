vector<Book> Library::searchBooks(const string& query) const {
    vector<Book> results;
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getTitle().find(query) != string::npos ||
            books[i].getAuthor().find(query) != string::npos ||
            books[i].getSummary().find(query) != string::npos) {
            results.push_back(books[i]);
        }
    }
    return results;
}