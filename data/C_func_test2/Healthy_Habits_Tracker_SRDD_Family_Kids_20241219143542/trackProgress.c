void trackProgress() {
    int index;
    printf("Enter the profile number (0-9): ");
    scanf("%d", &index);
    if (index < 0 || index >= 10) {
        printf("Invalid profile number.\n");
        return;
    }
    printf("Track progress for %s:\n", family[index].name);
    printf("Enter the nutrition intake (in grams): ");
    scanf("%d", &family[index].currentNutrition);
    printf("Enter the physical activity (in minutes): ");
    scanf("%d", &family[index].currentActivity);
    printf("Enter the sleep duration (in hours): ");
    scanf("%d", &family[index].currentSleep);
    printf("Enter the screen time (in hours): ");
    scanf("%d", &family[index].currentScreenTime);
    printf("Progress tracked for %s.\n", family[index].name);
}