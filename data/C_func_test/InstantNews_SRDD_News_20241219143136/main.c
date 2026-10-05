int main(int argc, char *argv[]) {
    int choice, numArticles = 5;
    BookmarkManager* bookmarkManager = createBookmarkManager();
    NewsArticle* articles = fetchBreakingNews();
 
    while (1) {
        displayMainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayNews(articles, numArticles);
                break;
            case 2:
                addBookmark(bookmarkManager, &articles[0]); 
                printf("Article bookmarked!\n");
                break;
            case 3:
                displayBookmarks(bookmarkManager);
                break;
            case 4:
                shareArticle(&articles[0]); 
                break;
            case 5:
                printf("Exiting the application...\n");
                free(articles);
                free(bookmarkManager);
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}