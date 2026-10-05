void search_articles(NewsSource *sources) {
    char search_term[256];
    printf("Enter a search term: ");
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = 0; 
    printf("Searching for: %s\n", search_term);
    for (size_t i = 0; i < sources->count; i++) {
        if (strstr(sources->articles[i].title, search_term) != NULL ||
            strstr(sources->articles[i].content, search_term) != NULL) {
            printf("Found: %s\n", sources->articles[i].title);
        }
    }
}