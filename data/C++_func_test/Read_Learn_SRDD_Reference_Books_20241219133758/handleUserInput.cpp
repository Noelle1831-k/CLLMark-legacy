void handleUserInput(int choice) {
        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            viewBooksByCategory();
            break;
        case 4:
            bookmarkBook();
            break;
        case 5:
            viewBookmarks();
            break;
        case 6:
            customizeReadingExperience();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }