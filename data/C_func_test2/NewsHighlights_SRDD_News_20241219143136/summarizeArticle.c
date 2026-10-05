char* summarizeArticle(char* article) {
    static char summary[100];
    char keywords[][10] = {"market", "win", "AI", "final", "technology"};
    int keywordCount = sizeof(keywords) / sizeof(keywords[0]);
    char* importantSentence = extractKeywords(article, keywords, keywordCount);
    if (importantSentence) {
        strncpy(summary, importantSentence, 99);
        summary[99] = '\0';
    } else {
        strncpy(summary, article, 99);
        summary[99] = '\0';
    }
    return summary;
}