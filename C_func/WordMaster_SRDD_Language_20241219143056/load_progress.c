void load_progress(const char* username) {
    FILE *file = fopen("progress.txt", "r");
    if (file == NULL) {
        printf("No progress file found. Starting fresh.\n");
        return;
    }
    char saved_username[50];
    int quiz_score;
    while (fscanf(file, "%s %d", saved_username, &quiz_score) != EOF) {
        if (strcmp(saved_username, username) == 0) {
            printf("Welcome back, %s! Your last quiz score was: %d\n", username, quiz_score);
            fclose(file);
            return;
        }
    }
    printf("No previous progress found for %s. Starting fresh.\n", username);
    fclose(file);
}