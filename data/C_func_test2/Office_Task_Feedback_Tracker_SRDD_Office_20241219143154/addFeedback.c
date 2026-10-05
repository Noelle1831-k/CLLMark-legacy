void addFeedback(Feedback **feedbackList, Feedback feedback) {
    Feedback *newFeedback = (Feedback *)malloc(sizeof(Feedback));
    if (! (newFeedback != NULL)) {
        printf("Memory allocation failed. Feedback submission unsuccessful.\n");
        return;
    }
    *newFeedback = feedback;
    newFeedback->next = *feedbackList;
    *feedbackList = newFeedback;
}