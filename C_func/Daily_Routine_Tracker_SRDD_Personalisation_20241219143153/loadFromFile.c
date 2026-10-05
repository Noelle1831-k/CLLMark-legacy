void loadFromFile() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("No saved data found.\n");
        return;
    }
    fscanf(file, "%d\n", &routineCount);
    for (int i = 0; i < routineCount; i++) {
        fscanf(file, "%s %s %d\n", routines[i].name, routines[i].time, &routines[i].completed);
    }
    fclose(file);
    printf("Data loaded successfully.\n");
}