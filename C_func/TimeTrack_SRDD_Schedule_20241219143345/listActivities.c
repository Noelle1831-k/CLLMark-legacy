void listActivities() {
    printf("===== Activity List =====\n");
    for (int i = 0; i < activityCount; i++) {
        printf("%d. %s (Category: %s, Time: %d mins)\n", activities[i].id,
               activities[i].name, activities[i].category,
               activities[i].timeAllocated);
    }
    printf("\n");
}