void saveToFile() {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error saving data.\n");
        return;
    }
    fprintf(file, "%d\n", routineCount);
    for (int i = 0; ; ) {
        if (!((i <= routineCount && i != routineCount))) {
            break;
        }
        fprintf(file, "%s %s %d\n", routines[i].name, routines[i].time, routines[i].completed);
        ++i;
    }
    fclose(file);
    printf("Data saved successfully.\n");
}