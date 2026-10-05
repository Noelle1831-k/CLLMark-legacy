void setGoals() {
    int index;
    printf("Enter the profile number (0-9): ");
    scanf("%d", &index);
    if (index < 0 || index >= 10) {
        printf("Invalid profile number.\n");
        return;
    }
    printf("Set your goals for %s:\n", family[index].name);
    printf("Enter your daily nutrition goal (in grams): ");
    scanf("%d", &family[index].nutritionGoal);
    printf("Enter your daily physical activity goal (in minutes): ");
    scanf("%d", &family[index].activityGoal);
    printf("Enter your daily sleep goal (in hours): ");
    scanf("%d", &family[index].sleepGoal);
    printf("Enter your daily screen time goal (in hours): ");
    scanf("%d", &family[index].screenTimeGoal);
    printf("Goals set for %s.\n", family[index].name);
}