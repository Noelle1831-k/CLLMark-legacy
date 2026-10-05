void Library::addBookToShelf(const string &shelfName, const Book &book) {
    for (vector<Shelf>::iterator it = shelves.begin(); it != shelves.end(); ++it) {
        if (it->getShelfName() == shelfName) {
            it->addBook(book);
            cout << "Book \"" << book.getTitle() << "\" added to shelf \"" << shelfName << "\"." << endl;
            return;
        }
    }
    cout << "Shelf \"" << shelfName << "\" not found!" << endl;
}