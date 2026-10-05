void Library::removeBookFromShelf(const string &shelfName, const string &title) {
    for (vector<Shelf>::iterator it = shelves.begin(); it != shelves.end(); ++it) {
        if (it->getShelfName() == shelfName) {
            it->removeBook(title);
            return;
        }
    }
    cout << "Shelf \"" << shelfName << "\" not found!" << endl;
}