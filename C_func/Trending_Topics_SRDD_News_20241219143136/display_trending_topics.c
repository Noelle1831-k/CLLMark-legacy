void display_trending_topics(char** topics) {
    printf("\n--- Trending Topics ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, topics[i]);
    }
}