void paginate_news(char **articles, int articles_per_page) {
    printf("Paginating news...\n");
    int count = 0;
    for (int i = 0; articles[i] != NULL; i++) {
        if (count == articles_per_page) {
            printf("-- Press Enter to continue --\n");
            getchar();
            count = 0;
        }
        printf("%s\n", articles[i]);
        count++;
    }
}