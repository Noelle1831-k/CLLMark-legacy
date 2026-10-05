vector<Book> Library::filterByGenre(const string& genre) const {
    vector<Book> results;
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getGenre() == genre) {
            results.push_back(books[i]);
        }
    }
    return results;
}