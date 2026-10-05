void Shelf::displayBooks() const {
    cout << "Shelf: " << shelfName << endl;
    for (vector<Book>::const_iterator it = books.begin(); it != books.end(); ++it) {
        it->display();
    }
}