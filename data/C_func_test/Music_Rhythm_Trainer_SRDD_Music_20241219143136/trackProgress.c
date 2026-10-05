void trackProgress(int exercisesCompleted) {
    if (exercisesCompleted < 0) {
        printf("Invalid number of exercises.\n");
        return;
    }
    printf("You have completed %d exercises.\n", exercisesCompleted);
}