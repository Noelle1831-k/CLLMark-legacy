int loadActivitiesFromFile() {
    FILE *file = fopen("activities.txt", "r");
    if (!file) return 0;
    while (fscanf(file, "%d %[^\t]\t%[^\t]\t%d", &activities[activityCount].id,
                  activities[activityCount].name,
                  activities[activityCount].category,
                  &activities[activityCount].timeAllocated) != EOF) {
        activityCount++;
    }
    fclose(file);
    return 1;
}