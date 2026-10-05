void submitFeedback(const char *feedback, const char *name) {
    char entry[600];
    snprintf(entry, sizeof(entry), "Name: %s\nFeedback: %s\nStatus: New\nCategory: Uncategorized\n\n", name, feedback);
    storeFeedback(entry);
}