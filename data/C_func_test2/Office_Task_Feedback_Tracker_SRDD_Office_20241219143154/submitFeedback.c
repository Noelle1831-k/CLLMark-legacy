void submitFeedback(Feedback **feedbackList) {
    Feedback newFeedback;
    char taskId[20];
    printf("Enter Task ID: ");
    scanf("%s", taskId);
    getchar();
    if (!validateTaskId(atoi(taskId))) {
        printf("Invalid Task ID. Please try again.\n");
        return;
    }
    printf("Enter your feedback (suggestion/concern): ");
    fgets(newFeedback.feedbackText, sizeof(newFeedback.feedbackText), stdin);
    newFeedback.feedbackText[strcspn(newFeedback.feedbackText, "\n")] = 0;  
    newFeedback.taskId = atoi(taskId);
    printf("Categorizing feedback...\n");
    categorizeFeedback(newFeedback.feedbackText, &newFeedback);
    addFeedback(feedbackList, newFeedback);
    printf("Feedback submitted successfully!\n");
}