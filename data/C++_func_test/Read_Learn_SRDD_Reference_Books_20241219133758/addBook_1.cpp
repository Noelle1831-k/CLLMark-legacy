void addBook() {
        string category;
        string content;
        string author;
        string title;
        
        printf("Enter book title: ");
        cin.ignore();
        getline(cin, title);
        printf("Enter book author: ");
        getline(cin, author);
        printf("Enter book category: ");
        getline(cin, category);
        printf("Enter book content: ");
        getline(cin, content);
        library.addBook(Book(title, author, category, content));
        printf("Book added successfully!\n");
    }