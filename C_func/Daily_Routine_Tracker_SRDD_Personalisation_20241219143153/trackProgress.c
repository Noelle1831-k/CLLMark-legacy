void trackProgress() {
    char name[50];
    printf("Enter routine name to mark as completed: ");
    scanf("%s", name);
    for (int i = 0; i < routineCount; i++) {
        if (strcmp(routines[i].name, name) == 0) {
            routines[i].completed = 1;
            printf("Routine marked as completed.\n");
            return;
        }
    }
    printf("Routine not found.\n");
}