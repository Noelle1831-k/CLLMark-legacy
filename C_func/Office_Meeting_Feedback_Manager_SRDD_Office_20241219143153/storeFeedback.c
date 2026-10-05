int storeFeedback(Feedback feedback) {
    FILE *file = fopen(FEEDBACK_FILE, "a");
    if (!file) {
        perror("Error opening feedback file");
        return 0;
    }
    sanitizeInput(feedback.comments); 
    fprintf(file, "%s,%d,%d,%s\n", feedback.name, feedback.meetingID, feedback.rating, feedback.comments);
    fclose(file);
    return 1;
}