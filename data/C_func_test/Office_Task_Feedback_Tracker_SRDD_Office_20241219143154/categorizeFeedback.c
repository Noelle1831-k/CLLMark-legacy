void categorizeFeedback(char *feedbackText, Feedback *feedback) {
    if (strstr(feedbackText, "issue") != NULL || strstr(feedbackText, "problem") != NULL) {
        strcpy(feedback->category, "Concern");
    } else if (strstr(feedbackText, "suggest") != NULL || strstr(feedbackText, "improve") != NULL) {
        strcpy(feedback->category, "Suggestion");
    } else if (strstr(feedbackText, "appreciate") != NULL || strstr(feedbackText, "like") != NULL) {
        strcpy(feedback->category, "Appreciation");
    } else {
        strcpy(feedback->category, "General");
    }
}