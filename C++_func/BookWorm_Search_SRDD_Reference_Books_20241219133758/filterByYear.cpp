vector<Book> Library::filterByYear(int year) const {
    vector<Book> results;
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getPublicationYear() == year) {
            results.push_back(books[i]);
        }
    }
    return results;
}