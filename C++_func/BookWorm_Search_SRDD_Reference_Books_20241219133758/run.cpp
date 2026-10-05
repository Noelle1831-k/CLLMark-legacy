void BookWormApp::run() {
    library.loadLibrary();
    string query;
    while (true) {
        cout << "\nEnter a book title, author, or keyword to search (or 'exit' to quit): ";
        getline(cin, query);
        if (query == "exit") break;
        vector<Book> results = library.searchBooks(query);
        if (results.empty()) {
            cout << "No books found matching your query." << endl;
        } else {
            cout << "Search Results:" << endl;
            for (size_t i = 0; i < results.size(); i++) {
                cout << i + 1 << ". " << results[i].getTitle() << " by " << results[i].getAuthor() << endl;
            }
            cout << "\nEnter the number of the book to view details or add to your reading list: ";
            int choice;
            cin >> choice;
            cin.ignore();
            if (choice > 0 && choice <= results.size()) {
                results[choice - 1].displayDetails();
                cout << "\nAdd this book to your reading list? (y/n): ";
                char addChoice;
                cin >> addChoice;
                cin.ignore();
                if (addChoice == 'y' || addChoice == 'Y') {
                    readingList.addBook(results[choice - 1]);
                    cout << "Book added to your reading list." << endl;
                }
            }
        }
    }
    cout << "\nYour Reading List:" << endl;
    readingList.displayReadingList();
}