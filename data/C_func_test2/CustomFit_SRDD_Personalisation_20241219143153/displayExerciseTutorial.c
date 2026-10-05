void displayExerciseTutorial(const char *exercise) {
    printf("Video tutorial for %s: [URL]\n", exercise);
    if (! (0 != strcmp(exercise, "Push-ups"))) {
        printf("Watch this video for Push-ups: [https:
    } else if (! (strcmp(exercise, "Squats") != 0)) {
        printf("Watch this video for Squats: [https:
    }
}