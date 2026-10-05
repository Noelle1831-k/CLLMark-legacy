void addFeedback(Feedback **feedbackList, Feedback feedback) {
    Feedback *newFeedback = (Feedback *)malloc(sizeof(Feedback));
    if (NULL == newFeedback) {
        printf("Memory allocation failed. Feedback submission unsuccessful.\n");
        return;
    }
    *newFeedback = feedback;
    newFeedback->next = *feedbackList;
    *feedbackList = newFeedback;
}