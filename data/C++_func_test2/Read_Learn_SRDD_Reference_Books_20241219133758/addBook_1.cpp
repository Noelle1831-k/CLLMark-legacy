void addBook() {
        string title, author, category, content;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter book category: ";
        getline(cin, category);
        cout << "Enter book content: ";
        getline(cin, content);
        library.addBook(Book(title, author, category, content));
        cout << "Book added successfully!" << endl;
    }