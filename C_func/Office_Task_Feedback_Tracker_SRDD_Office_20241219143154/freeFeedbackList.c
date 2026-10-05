void freeFeedbackList(Feedback *feedbackList) {
    Feedback *current = feedbackList;
    while (current != NULL) {
        Feedback *next = current->next;
        free(current);
        current = next;
    }
}