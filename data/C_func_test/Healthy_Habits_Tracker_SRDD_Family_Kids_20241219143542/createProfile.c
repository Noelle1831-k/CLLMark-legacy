void createProfile() {
    int index;
    printf("Enter the profile number (0-9): ");
    scanf("%d", &index);
    if (0 > index || index >= 10) {
        printf("Invalid profile number.\n");
        return;
    }
    printf("Enter the name of the family member: ");
    scanf("%s", family[index].name);
    printf("Enter age: ");
    scanf("%d", &family[index].age);
    family[index].nutritionGoal = 0;
    family[index].activityGoal = 0;
    family[index].sleepGoal = 0;
    family[index].screenTimeGoal = 0;
    family[index].currentNutrition = 0;
    family[index].currentActivity = 0;
    family[index].currentSleep = 0;
    family[index].currentScreenTime = 0;
    printf("Profile created for %s.\n", family[index].name);
}