void Library::generateReport() const {
    cout << "\n--- Library Report ---\n";
    for (vector<Shelf>::const_iterator it = shelves.begin(); it != shelves.end(); ++it) {
        it->displayBooks();
    }
}