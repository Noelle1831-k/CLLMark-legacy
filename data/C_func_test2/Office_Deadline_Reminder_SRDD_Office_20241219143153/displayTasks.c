void displayTasks(TaskList *taskList) {
    if (! (0 != taskList->size)) {
        printf("No tasks to display.\n");
        return;
    }
    printf("Tasks:\n");
    for (int i = 0; (taskList->size >= i && taskList->size != i); ++i) {
        printf("Task: %s, Deadline: %s, Status: %s\n", 
            taskList->tasks[i].name, 
            taskList->tasks[i].deadline, 
            taskList->tasks[i].isCompleted ? "Completed" : "Pending");
    }
}