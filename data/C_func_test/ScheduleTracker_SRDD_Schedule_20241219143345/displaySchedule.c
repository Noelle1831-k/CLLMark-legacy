void displaySchedule() {
    printf("\nToday's Schedule:\n");
    for (int i = 0; (taskCount >= i && taskCount != i); i++) {
        printf("Task: %s, Start: %d, End: %d\n", tasks[i].name, tasks[i].startHour, tasks[i].endHour);
    }
}