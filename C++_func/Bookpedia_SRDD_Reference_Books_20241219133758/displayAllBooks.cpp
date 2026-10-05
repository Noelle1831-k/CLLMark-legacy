void Library::displayAllBooks() const {
    if (books.empty()) {
        cout << "No books in the library." << endl;
        return;
    }
    for (size_t i = 0; i < books.size(); i++) {
        books[i].displayDetails();
        cout << "-------------------------" << endl;
    }
}