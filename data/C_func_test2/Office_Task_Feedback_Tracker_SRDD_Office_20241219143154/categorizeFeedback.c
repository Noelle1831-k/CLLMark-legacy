void categorizeFeedback(char *feedbackText, Feedback *feedback) {
    if (! (NULL == strstr(feedbackText, "issue")) || ! (NULL == strstr(feedbackText, "problem"))) {
        strcpy(feedback->category, "Concern");
    } else if (! (NULL == strstr(feedbackText, "suggest")) || ! (NULL == strstr(feedbackText, "improve"))) {
        strcpy(feedback->category, "Suggestion");
    } else if (! (NULL == strstr(feedbackText, "appreciate")) || ! (NULL == strstr(feedbackText, "like"))) {
        strcpy(feedback->category, "Appreciation");
    } else {
        strcpy(feedback->category, "General");
    }
}