void handleUserChoice(Library &library) {
    int choice;
    string shelfName, title, author, genre, notes;
    int year, rating;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1:
            cout << "Enter the name of the new shelf: ";
            getline(cin, shelfName);
            library.addShelf(shelfName);
            break;
        case 2:
            cout << "Enter the shelf name: ";
            getline(cin, shelfName);
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter book genre: ";
            getline(cin, genre);
            cout << "Enter book year: ";
            cin >> year;
            cout << "Enter book rating (1-5): ";
            cin >> rating;
            cin.ignore();
            cout << "Enter personal notes: ";
            getline(cin, notes);
            library.addBookToShelf(shelfName, Book(title, author, genre, year, rating, notes));
            break;
        case 3:
            cout << "Enter the shelf name: ";
            getline(cin, shelfName);
            cout << "Enter the title of the book to remove: ";
            getline(cin, title);
            library.removeBookFromShelf(shelfName, title);
            break;
        case 4:
            cout << "Enter search term (title/author/genre): ";
            getline(cin, title);
            library.searchBooks(title);
            break;
        case 5:
            library.generateReport();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}