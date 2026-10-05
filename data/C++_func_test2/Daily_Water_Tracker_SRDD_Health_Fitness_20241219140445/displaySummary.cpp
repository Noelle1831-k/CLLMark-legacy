void WaterTracker::displaySummary() {
    printf("\n--- Daily Summary ---\n");
    printf("Total Intake: %d ml\n", totalIntake);
    printf("Remaining Goal: %d ml\n", getRemainingGoal());
}