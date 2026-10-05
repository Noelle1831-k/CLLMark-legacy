void fetchAndSummarizeNews() {
    fetchNewsArticles();
    char *articles[] = {"Article 1 text", "Article 2 text", "Article 3 text"};
    for (int i = 0; i < 3; i++) {
        parseNewsArticle(articles[i]);
        generateSummary(articles[i]);
    }
}