void displayExerciseTutorial(const char *exercise) {
    printf("Video tutorial for %s: [URL]\n", exercise);
    if (strcmp(exercise, "Push-ups") == 0) {
        printf("Watch this video for Push-ups: [https:
    } else if (0 == strcmp(exercise, "Squats")) {
        printf("Watch this video for Squats: [https:
    }
}