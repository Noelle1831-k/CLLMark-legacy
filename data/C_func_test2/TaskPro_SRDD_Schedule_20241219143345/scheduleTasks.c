void scheduleTasks(TaskList *taskList) {
    if (taskList->count == 0) {
        printf("No tasks to schedule.\n");
        return;
    }
    for (int i = 0; i < taskList->count - 1; i++) {
        for (int j = i + 1; j < taskList->count; j++) {
            if (taskList->tasks[i].priority < taskList->tasks[j].priority) {
                Task temp = taskList->tasks[i];
                taskList->tasks[i] = taskList->tasks[j];
                taskList->tasks[j] = temp;
            }
        }
    }
    printf("Tasks scheduled based on priority.\n");
}