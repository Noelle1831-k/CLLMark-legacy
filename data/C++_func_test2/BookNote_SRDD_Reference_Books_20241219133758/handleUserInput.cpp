void handleUserInput(NoteManager &noteManager, SearchEngine &searchEngine) {
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1: {
            string title, author, isbn;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            Book newBook(title, author, isbn);
            noteManager.addBook(newBook);
            cout << "Book added successfully!\n";
            break;
        }
        case 2: {
            string bookTitle, chapterName;
            cout << "Enter book title: ";
            getline(cin, bookTitle);
            cout << "Enter chapter name: ";
            getline(cin, chapterName);
            noteManager.addChapterToBook(bookTitle, chapterName);
            cout << "Chapter added successfully!\n";
            break;
        }
        case 3: {
            string bookTitle, chapterName, noteText, highlight, imagePath, audioPath;
            cout << "Enter book title: ";
            getline(cin, bookTitle);
            cout << "Enter chapter name: ";
            getline(cin, chapterName);
            Note newNote;
            cout << "Enter note text: ";
            getline(cin, noteText);
            newNote.addText(noteText);
            cout << "Enter highlighted passage: ";
            getline(cin, highlight);
            newNote.addHighlight(highlight);
            cout << "Enter image path (optional): ";
            getline(cin, imagePath);
            if (!imagePath.empty()) newNote.attachImage(imagePath);
            cout << "Enter audio path (optional): ";
            getline(cin, audioPath);
            if (!audioPath.empty()) newNote.attachAudio(audioPath);
            noteManager.addNoteToChapter(bookTitle, chapterName, newNote);
            cout << "Note added successfully!\n";
            break;
        }
        case 4: {
            string keyword;
            cout << "Enter keyword to search for books: ";
            getline(cin, keyword);
            vector<string> results = searchEngine.searchBooks(keyword);
            cout << "Search Results:\n";
            for (size_t i = 0; i < results.size(); i++) {
                cout << results[i] << endl;
            }
            break;
        }
        case 5: {
            string keyword;
            cout << "Enter keyword to search for notes: ";
            getline(cin, keyword);
            vector<string> results = searchEngine.searchNotes(keyword);
            cout << "Search Results:\n";
            for (size_t i = 0; i < results.size(); i++) {
                cout << results[i] << endl;
            }
            break;
        }
        case 6:
            cout << "Exiting application. Goodbye!\n";
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}