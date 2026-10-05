int evaluateResponse(ExerciseManager *manager, Exercise *exercise, const char *response) {
    if (strcmp(response, exercise->correctAnswer) == 0) {
        printf("Correct!\n");
        return 100;
    } else {
        printf("Incorrect.\n");
        return 0;
    }
}