void run() {
    printf("Running application...\n");
    while (1) {
        displayMenu();
        int choice = getUserInput();
        switch (choice) {
            case 1:
                searchResources();
                break;
            case 2:
                browseCategories();
                break;
            case 3:
                listBookmarks();
                break;
            case 4: {
                printf("Enter title to bookmark: ");
                char bookmarkTitle[MAX_TITLE_LENGTH];
                scanf(" %[^\n]s", bookmarkTitle);
                addBookmark(bookmarkTitle);
                break;
            }
            case 5:
                listNotes();
                break;
            case 6:
                addNote();
                break;
            case 7:
                listHighlights();
                break;
            case 8:
                addHighlight();
                break;
            case 9:
                printf("Exiting application...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}