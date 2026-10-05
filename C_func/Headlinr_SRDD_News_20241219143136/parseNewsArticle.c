void parseNewsArticle(char *articleText) {
    printf("Parsing article: %s\n", articleText);
    char keywords[5][20] = {"Politics", "Sports", "Technology", "Health", "Finance"};
    for (int i = 0; i < 5; i++) {
        printf("Extracted keyword: %s\n", keywords[i]);
    }
}