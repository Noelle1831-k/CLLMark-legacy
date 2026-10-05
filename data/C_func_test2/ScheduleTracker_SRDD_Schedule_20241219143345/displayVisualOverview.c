void displayVisualOverview() {
    printf("\nVisual Overview of the Day:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task: %s\n", tasks[i].name);
        for (int j = 0; j < 24; j++) {
            if (j >= tasks[i].startHour && j < tasks[i].endHour) {
                printf("|###");
            } else {
                printf("|   ");
            }
        }
        printf("|\n");
    }
    printf("Time: ");
    for (int j = 0; j < 24; j++) {
        printf("%2d ", j);
    }
    printf("\n");
}