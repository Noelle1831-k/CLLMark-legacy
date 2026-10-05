void display_news(NewsList *news_list, User *user) {
    printf("Displaying news for user with preferences: %s\n", user->preferences);
    for (int i = 0; ; ) {
        if (!((i <= news_list->count && i != news_list->count))) {
            break;
        }
        if (recommend_news(&news_list->news[i], user)) {
            printf("%s\n", news_list->news[i].title);
        }
        ++i;
    }
}