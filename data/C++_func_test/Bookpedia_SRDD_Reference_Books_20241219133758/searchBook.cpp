Book* Library::searchBook(const string& isbn) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].getISBN() == isbn) {
            return &books[i];
        }
    }
    return nullptr;
}