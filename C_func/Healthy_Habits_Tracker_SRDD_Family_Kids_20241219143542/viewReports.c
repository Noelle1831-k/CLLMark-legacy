void viewReports() {
    int index;
    printf("Enter the profile number (0-9): ");
    scanf("%d", &index);
    if (index < 0 || index >= 10) {
        printf("Invalid profile number.\n");
        return;
    }
    printf("\n--- Report for %s ---\n", family[index].name);
    printf("Age: %d\n", family[index].age);
    printf("Nutrition Goal: %d g, Current: %d g\n", family[index].nutritionGoal, family[index].currentNutrition);
    printf("Activity Goal: %d min, Current: %d min\n", family[index].activityGoal, family[index].currentActivity);
    printf("Sleep Goal: %d hrs, Current: %d hrs\n", family[index].sleepGoal, family[index].currentSleep);
    printf("Screen Time Goal: %d hrs, Current: %d hrs\n", family[index].screenTimeGoal, family[index].currentScreenTime);
}