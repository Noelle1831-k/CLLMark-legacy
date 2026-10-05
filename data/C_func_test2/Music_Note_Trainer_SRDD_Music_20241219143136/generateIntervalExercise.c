void generateIntervalExercise() {
    char interval[10];
    randomInterval(interval);
    showExercise(interval);
    printf("Which of the following intervals is this?\n");
    printf("1. Unison\n2. Minor Second\n3. Major Third\n4. Minor Third\n");
    printf("Select a number from 1 to 4: ");
}