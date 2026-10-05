void handleEmployeeInput() {
    Feedback feedback;
    printf("\n==== Provide Feedback ====\n");
    clearInputBuffer();
    printf("Enter your name (max 50 characters): ");
    fgetsSafe(feedback.name, sizeof(feedback.name));
    printf("Enter meeting ID (positive integer): ");
    if (scanf("%d", &feedback.meetingID) != 1 || feedback.meetingID <= 0) {
        printf("Invalid meeting ID! Please enter a valid positive integer.\n");
        return;
    }
    printf("Rate the meeting (1-5): ");
    if (scanf("%d", &feedback.rating) != 1 || feedback.rating < 1 || feedback.rating > 5) {
        printf("Invalid rating! Please provide a number between 1 and 5.\n");
        return;
    }
    clearInputBuffer();
    printf("Enter your comments (max 200 characters): ");
    fgetsSafe(feedback.comments, sizeof(feedback.comments));
    if (storeFeedback(feedback)) {
        printf("Feedback submitted successfully!\n");
    } else {
        printf("Error saving feedback. Please try again.\n");
    }
}