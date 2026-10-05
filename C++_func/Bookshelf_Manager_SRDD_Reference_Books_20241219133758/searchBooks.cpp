void Library::searchBooks(const string &term) const {
    cout << "Searching for books matching \"" << term << "\"..." << endl;
    bool found = false;
    for (vector<Shelf>::const_iterator it = shelves.begin(); it != shelves.end(); ++it) {
        for (vector<Book>::const_iterator bookIt = it->getBooks().begin(); bookIt != it->getBooks().end(); ++bookIt) {
            if (bookIt->getTitle().find(term) != string::npos ||
                bookIt->getAuthor().find(term) != string::npos ||
                bookIt->getGenre().find(term) != string::npos) {
                bookIt->display();
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No books found matching \"" << term << "\"." << endl;
    }
}