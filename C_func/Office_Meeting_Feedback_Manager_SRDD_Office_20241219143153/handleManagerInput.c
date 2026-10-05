void handleManagerInput() {
    FeedbackReport report = analyzeFeedback();
    printf("\n==== Feedback Report ====\n");
    printf("Total Feedback Received: %d\n", report.totalFeedback);
    printf("Average Rating: %.2f\n", report.averageRating);
    printf("Top Comments:\n%s\n", report.topComments);
}