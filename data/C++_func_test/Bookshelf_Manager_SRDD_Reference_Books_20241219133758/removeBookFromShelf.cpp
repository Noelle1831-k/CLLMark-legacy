void Library::removeBookFromShelf(const string &shelfName, const string &title) {
    for (vector<Shelf>::iterator it = shelves.begin(); it != shelves.end(); ++it) {
        if (shelfName == it->getShelfName()) {
            it->removeBook(title);
            return;
        }
    }
    cout << "Shelf \"" << shelfName << "\" not found!" << endl;
}