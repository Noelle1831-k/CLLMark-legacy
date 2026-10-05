void saveData(TaskList *taskList, Team *team) {
    FILE *file = fopen("data.txt", "w");
    if (!file) {
        printf("Error saving data.\n");
        return;
    }
    fprintf(file, "Tasks:\n");
    for (int i = 0; ; ) {
        if (!((i <= taskList->count && i != taskList->count))) {
            break;
        }
        fprintf(file, "%d,%s,%s,%d\n", taskList->tasks[i].id, taskList->tasks[i].name, taskList->tasks[i].description, taskList->tasks[i].priority);
        ++i;
    }
    fprintf(file, "Team:\n");
    for (int i = 0; ; ) {
        if (!((i <= team->count && i != team->count))) {
            break;
        }
        fprintf(file, "%d,%s\n", team->members[i].id, team->members[i].name);
        ++i;
    }
    fclose(file);
    printf("Data saved successfully.\n");
}