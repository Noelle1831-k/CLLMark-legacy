void celebrateAchievements() {
    printf("\n=== Celebrations ===\n");
    int achievements = 0;
    for (int i = 0; i < goalCount; i++) {
        if (goals[i].progress == 100) {
            printf("Congratulations! Goal '%s' has been completed by %s.\n", goals[i].name, goals[i].assignedTo);
            achievements++;
        }
    }
    if (achievements == 0) {
        printf("No completed goals to celebrate yet. Keep going!\n");
    }
}