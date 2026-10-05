void addRoutine() {
    if (routineCount >= MAX_ROUTINES) {
        printf("Routine limit reached. Cannot add more routines.\n");
        return;
    }
    printf("Enter routine name: ");
    scanf("%s", routines[routineCount].name);
    printf("Enter routine time (HH:MM): ");
    scanf("%s", routines[routineCount].time);
    routines[routineCount].completed = 0; 
    routineCount++;
    printf("Routine added successfully.\n");
}