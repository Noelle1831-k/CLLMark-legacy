void display_result(int sentiment_result) {
    if (sentiment_result == 1) {
        printf("The sentiment of the text is: Positive\n");
    } else if (sentiment_result == -1) {
        printf("The sentiment of the text is: Negative\n");
    } else {
        printf("The sentiment of the text is: Neutral\n");
    }
}