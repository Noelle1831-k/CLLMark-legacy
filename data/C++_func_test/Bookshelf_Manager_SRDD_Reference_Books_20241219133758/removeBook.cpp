void Shelf::removeBook(const string &title) {
    for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == title) {
            books.erase(it);
            cout << "Book \"" << title << "\" removed successfully." << endl;
            return;
        }
    }
    cout << "Book \"" << title << "\" not found on shelf \"" << shelfName << "\"." << endl;
}