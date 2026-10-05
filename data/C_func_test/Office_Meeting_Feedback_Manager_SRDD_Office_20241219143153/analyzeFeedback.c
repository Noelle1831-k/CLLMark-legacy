FeedbackReport analyzeFeedback() {
    FILE *file = fopen(FEEDBACK_FILE, "r");
    if (!file) {
        perror("Error opening feedback file");
        FeedbackReport emptyReport = {0, 0.0, ""};
        return emptyReport;
    }
    int totalFeedback = 0, totalRating = 0, rating;
    char line[256], comments[1024] = "";
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        rating = atoi(token);
        token = strtok(NULL, ",");
        totalFeedback++;
        totalRating += rating;
        if (strlen(comments) + strlen(token) + 2 < sizeof(comments)) {
            strcat(comments, token);
            strcat(comments, "\n");
        }
    }
    fclose(file);
    FeedbackReport report = {totalFeedback, totalFeedback ? (float)totalRating / totalFeedback : 0.0, ""};
    strncpy(report.topComments, comments, sizeof(report.topComments) - 1);
    return report;
}