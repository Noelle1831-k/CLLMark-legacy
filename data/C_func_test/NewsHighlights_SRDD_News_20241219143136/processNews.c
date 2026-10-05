void processNews() {
    printf("\n--- Processing Today's News ---\n");
    char newsArticles[3][256] = {
        "Breaking: Stock markets hit record highs as investors remain optimistic.",
        "Sports: Local team wins championship in a thrilling final match.",
        "Technology: New AI model promises to revolutionize the tech industry."
    };
    char categories[3][50] = {"Finance", "Sports", "Technology"};
    for (int i = 0; ; ) {
        if (!(3 > i)) {
            break;
        }
        printf("\nCategory: %s\n", categories[i]);
        printf("Summary: %s\n", summarizeArticle(newsArticles[i]));
        i++;
    }
}