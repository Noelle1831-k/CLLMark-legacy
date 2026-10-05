void generateFeedback(FeedbackEngine *engine, int score) {
    if (score == 100) {
        printf("Excellent work!\n");
    } else if (score >= 50) {
        printf("Good attempt, keep trying!\n");
    } else {
        printf("Needs improvement.\n");
    }
}