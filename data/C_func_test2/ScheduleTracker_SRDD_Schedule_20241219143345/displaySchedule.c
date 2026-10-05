void displaySchedule() {
    printf("\nToday's Schedule:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task: %s, Start: %d, End: %d\n", tasks[i].name, tasks[i].startHour, tasks[i].endHour);
    }
}