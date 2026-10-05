void addActivity() {
    if (activityCount >= MAX_ACTIVITIES) {
        printf("Activity limit reached.\n");
        return;
    }
    Activity newActivity;
    newActivity.id = activityCount + 1;
    printf("Enter activity name: ");
    getInput(newActivity.name, 50);
    printf("Enter category: ");
    getInput(newActivity.category, 20);
    printf("Enter time allocated (in minutes): ");
    newActivity.timeAllocated = getValidatedInt(0, 1440);
    activities[activityCount] = newActivity;
    activityCount++;
    if (!saveActivitiesToFile()) {
        printf("Failed to save activity to file. Try again later.\n");
    } else {
        printf("Activity added successfully!\n");
    }
}