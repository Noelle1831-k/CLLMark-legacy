void handleUserChoice(int choice, ArticleDB *db, UserProfile *profile) {
    char query[MAX_INPUT];
    int article_id;
    switch (choice) {
        case 1:
            printf("Enter search query: ");
            fgets(query, MAX_INPUT, stdin);
            query[strcspn(query, "\n")] = 0;  
            searchArticles(db, query);
            break;
        case 2:
            displaySavedArticles(profile);
            break;
        case 3:
            printf("Enter article ID to share: ");
            scanf("%d", &article_id);
            shareArticle(article_id);
            break;
        case 4:
            printf("Enter source URL to bookmark: ");
            fgets(query, MAX_INPUT, stdin);
            query[strcspn(query, "\n")] = 0;  
            bookmarkSource(profile, query);
            break;
        case 5:
            viewProfile(profile);
            break;
        case 6:
            printf("Exiting application...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}