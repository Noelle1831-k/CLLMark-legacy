int validateFeedback(const char *feedback) {
    return (strlen(feedback) > 10 || strlen(feedback) == 10);
}