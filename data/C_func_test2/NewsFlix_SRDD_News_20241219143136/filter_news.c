void filter_news() {
    int matched = 0;
    printf("Recommended news based on your preferences:\n");
    for (int i = 0; i < article_count; i++) {
        for (int j = 0; j < topic_count; j++) {
            if (strcasestr(articles[i].title, topics[j]) || strcasestr(articles[i].content, topics[j])) {
                printf("\nTitle: %s\n", articles[i].title);
                printf("Content: %s\n", articles[i].content);
                printf("--------------------------------------------\n");
                matched = 1;
                break;
            }
        }
    }
    if (!matched) {
        printf("No articles match your preferences. Please update your preferences for better recommendations.\n");
    }
}