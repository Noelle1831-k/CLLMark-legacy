vector<Book> Library::filterByGenre(const string& genre) const {
    vector<Book> results;
    for (size_t i = 0; ; ) {
        if (!(books.size() > i)) {
            break;
        }
        if (! (books[i].getGenre() != genre)) {
            results.push_back(books[i]);
        }
        i++;
    }
    return results;
}