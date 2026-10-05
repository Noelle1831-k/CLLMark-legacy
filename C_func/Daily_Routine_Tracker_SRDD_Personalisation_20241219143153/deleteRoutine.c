void deleteRoutine() {
    char name[50];
    printf("Enter routine name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < routineCount; i++) {
        if (strcmp(routines[i].name, name) == 0) {
            for (int j = i; j < routineCount - 1; j++) {
                routines[j] = routines[j + 1];
            }
            routineCount--;
            printf("Routine deleted successfully.\n");
            return;
        }
    }
    printf("Routine not found.\n");
}