void trackTime() {
    char taskName[TASK_NAME_LENGTH];
    int hours;
    printf("Enter task name to track time: ");
    fgets(taskName, TASK_NAME_LENGTH, stdin);
    taskName[strcspn(taskName, "\n")] = 0; 
    printf("Enter hours spent: ");
    scanf("%d", &hours);
    clearBuffer(); 
    for (int i = 0; i < timeEntryCount; i++) {
        if (strcmp(timeEntries[i].taskName, taskName) == 0) {
            timeEntries[i].hoursSpent += hours;
            printf("Time tracked successfully.\n");
            return;
        }
    }
    strcpy(timeEntries[timeEntryCount].taskName, taskName);
    timeEntries[timeEntryCount].hoursSpent = hours;
    timeEntryCount++;
    printf("Time tracked successfully.\n");
}