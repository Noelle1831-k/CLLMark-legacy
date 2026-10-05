void removeActivity() {
    int id;
    printf("Enter the Activity ID to remove: ");
    id = getValidatedInt(1, activityCount);
    int index = -1;
    for (int i = 0; i < activityCount; i++) {
        if (activities[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < activityCount - 1; i++) {
            activities[i] = activities[i + 1];
        }
        activityCount--;
        if (!saveActivitiesToFile()) {
            printf("Failed to save changes. Try again later.\n");
        } else {
            printf("Activity removed successfully!\n");
        }
    } else {
        printf("Activity not found.\n");
    }
}