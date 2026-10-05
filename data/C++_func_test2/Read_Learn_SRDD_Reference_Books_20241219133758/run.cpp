void run() {
        cout << "Welcome to Read--model GPT_4O &Learn!" << endl;
        library.loadBooksFromFile("books.txt");
        while (true) {
            displayMenu();
            int choice;
            cin >> choice;
            handleUserInput(choice);
        }
    }