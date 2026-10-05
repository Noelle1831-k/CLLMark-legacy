int analyze_sentiment(char *text) {
    int sentiment_score = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        if (is_positive(word)) {
            sentiment_score++;
        } else if (is_negative(word)) {
            sentiment_score--;
        }
        word = strtok(NULL, " ");
    }
    if (sentiment_score > 0) {
        return 1;  
    } else if (sentiment_score < 0) {
        return -1; 
    } else {
        return 0;  
    }
}