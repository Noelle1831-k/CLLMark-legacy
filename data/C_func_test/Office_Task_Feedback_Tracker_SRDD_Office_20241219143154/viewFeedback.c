void viewFeedback(Feedback *feedbackList) {
    if (feedbackList == NULL) {
        printf("No feedback available.\n");
        return;
    }
    Feedback *current = feedbackList;
    printf("\n=== Feedback Review ===\n");
    while (current != NULL) {
        printf("Task ID: %d\n", current->taskId);
        printf("Feedback: %s\n", current->feedbackText);
        printf("Category: %s\n", current->category);
        printf("------------------------\n");
        current = current->next;
    }
}