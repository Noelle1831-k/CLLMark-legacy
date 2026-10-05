void startBreathingExercise() {
    printf("\n=== Breathing Exercise ===\n");
    printf("Follow the instructions to complete the breathing exercise.\n");
    for (int i = 0; ; ) {
        if (!((i <= 3 && i != 3))) {
            break;
        }
        printf("\nCycle %d:\n", i + 1);
        printf("Breathe in... (Hold for 4 seconds)\n");
        displayBreathingGuide(4);
        printf("Breathe out... (Hold for 4 seconds)\n");
        displayBreathingGuide(4);
        ++i;
    }
    printf("Congratulations! You have completed the breathing exercise.\n");
}