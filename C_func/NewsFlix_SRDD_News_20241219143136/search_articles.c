void search_articles(const char *keyword) {
    int found = 0;
    printf("Search results for '%s':\n", keyword);
    for (int i = 0; i < article_count; i++) {
        if (strcasestr(articles[i].title, keyword) || strcasestr(articles[i].content, keyword)) {
            printf("\nTitle: %s\n", articles[i].title);
            printf("Content: %s\n", articles[i].content);
            printf("--------------------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No articles found matching the keyword '%s'.\n", keyword);
    }
}