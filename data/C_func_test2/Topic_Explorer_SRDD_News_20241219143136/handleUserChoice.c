void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            exploreTrendingTopics();
            break;
        case 2:
            searchForTopics();
            break;
        case 3:
            accessNewsArticles();
            break;
        case 4:
            saveArticle();
            break;
        case 5:
            shareArticle();
            break;
        case 0:
            printf("Exiting application...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}