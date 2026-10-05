int recommend_news(News *news, User *user) {
    char *preferences_copy = strdup(user->preferences); 
    char *token = strtok(preferences_copy, " ");
    while (token != NULL) {
        if (strstr(news->title, token) != NULL) {
            free(preferences_copy); 
            return 1;
        }
        token = strtok(NULL, " ");
    }
    free(preferences_copy); 
    return 0;
}