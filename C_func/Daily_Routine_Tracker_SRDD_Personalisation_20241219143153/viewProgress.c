void viewProgress() {
    if (routineCount == 0) {
        printf("No routines available to track progress.\n");
        return;
    }
    printf("\n--- Progress ---\n");
    for (int i = 0; i < routineCount; i++) {
        printf("%d. %s [%s]\n", i + 1, routines[i].name, routines[i].completed ? "Completed" : "Incomplete");
    }
}