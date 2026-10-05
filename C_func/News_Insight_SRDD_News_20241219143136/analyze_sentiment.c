void analyze_sentiment(NewsArticle *article) {
    char *positive_keywords[] = {"good", "positive", "great", "happy", "success"};
    char *negative_keywords[] = {"bad", "negative", "fail", "angry", "worst"};
    int positive_score = 0;
    int negative_score = 0;
    for (int i = 0; i < 5; i++) {
        if (strstr(article->content, positive_keywords[i]) != NULL) {
            positive_score++;
        }
        if (strstr(article->content, negative_keywords[i]) != NULL) {
            negative_score++;
        }
    }
    if (positive_score > negative_score) {
        strcpy(article->sentiment, "Positive");
    } else if (negative_score > positive_score) {
        strcpy(article->sentiment, "Negative");
    } else {
        strcpy(article->sentiment, "Neutral");
    }
}