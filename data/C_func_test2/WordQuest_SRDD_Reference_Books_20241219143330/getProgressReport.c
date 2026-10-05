void getProgressReport(ProgressTracker* tracker) {
    printf("Total Score: %d\n", tracker->totalScore);
    if (tracker->totalScore < 50) {
        printf("Keep practicing! You're doing great.\n");
    } else {
        printf("Excellent progress! Keep challenging yourself.\n");
    }
}