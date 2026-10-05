void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            addBookManually();
            break;
        case 2:
            scanAndAddBook();
            break;
        case 3:
            listBooks();
            break;
        case 4:
            searchBook();
            break;
        case 5:
            removeBook();
            break;
        case 6:
            updateReadingProgress();
            break;
        case 7:
            generateRecommendations();
            break;
        case 8:
            trackReadingProgress();
            break;
        case 9:
            printf("Exiting the application. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}