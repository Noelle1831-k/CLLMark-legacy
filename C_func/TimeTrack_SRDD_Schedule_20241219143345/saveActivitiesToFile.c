int saveActivitiesToFile() {
    FILE *file = fopen("activities.txt", "w");
    if (!file) return 0;
    for (int i = 0; i < activityCount; i++) {
        fprintf(file, "%d\t%s\t%s\t%d\n", activities[i].id,
                activities[i].name, activities[i].category,
                activities[i].timeAllocated);
    }
    fclose(file);
    return 1;
}