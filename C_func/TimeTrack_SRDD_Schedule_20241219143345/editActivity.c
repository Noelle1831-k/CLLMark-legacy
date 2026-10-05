void editActivity() {
    int id;
    printf("Enter the Activity ID to edit: ");
    id = getValidatedInt(1, activityCount);
    Activity *activity = NULL;
    for (int i = 0; i < activityCount; i++) {
        if (activities[i].id == id) {
            activity = &activities[i];
            break;
        }
    }
    if (activity) {
        printf("Editing activity: %s (Category: %s, Time: %d mins)\n",
               activity->name, activity->category, activity->timeAllocated);
        printf("Enter new activity name (or press Enter to skip): ");
        char newName[50];
        getInput(newName, 50);
        if (strlen(newName) > 0) strcpy(activity->name, newName);
        printf("Enter new category (or press Enter to skip): ");
        char newCategory[20];
        getInput(newCategory, 20);
        if (strlen(newCategory) > 0) strcpy(activity->category, newCategory);
        printf("Enter new time allocated (or 0 to skip): ");
        int newTime = getValidatedInt(0, 1440);
        if (newTime > 0) activity->timeAllocated = newTime;
        if (!saveActivitiesToFile()) {
            printf("Failed to save changes. Try again later.\n");
        } else {
            printf("Activity updated successfully!\n");
        }
    } else {
        printf("Activity not found.\n");
    }
}