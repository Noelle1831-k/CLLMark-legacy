void Library::removeBook(const string& isbn) {
    for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
        if (it->getISBN() == isbn) {
            books.erase(it);
            break;
        }
    }
}