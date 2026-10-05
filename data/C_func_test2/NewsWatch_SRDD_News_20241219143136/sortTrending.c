void sortTrending(NewsFeed *newsFeed) {
    printf("Sorting articles based on trending topics...\n");
    for (int i = 0; i < newsFeed->articleCount - 1; i++) {
        for (int j = i + 1; j < newsFeed->articleCount; j++) {
            if (strcmp(newsFeed->articles[i], newsFeed->articles[j]) > 0) {
                char *temp = newsFeed->articles[i];
                newsFeed->articles[i] = newsFeed->articles[j];
                newsFeed->articles[j] = temp;
            }
        }
    }
}