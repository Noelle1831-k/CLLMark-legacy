void viewRoutines() {
    if (routineCount == 0) {
        printf("No routines available.\n");
        return;
    }
    printf("\n--- Routines ---\n");
    for (int i = 0; i < routineCount; i++) {
        printf("%d. %s at %s [%s]\n", i + 1, routines[i].name, routines[i].time, routines[i].completed ? "Completed" : "Incomplete");
    }
}