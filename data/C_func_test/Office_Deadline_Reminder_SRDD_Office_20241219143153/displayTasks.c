void displayTasks(TaskList *taskList) {
    if (taskList->size == 0) {
        printf("No tasks to display.\n");
        return;
    }
    printf("Tasks:\n");
    for (int i = 0; i < taskList->size; i++) {
        printf("Task: %s, Deadline: %s, Status: %s\n", 
            taskList->tasks[i].name, 
            taskList->tasks[i].deadline, 
            taskList->tasks[i].isCompleted ? "Completed" : "Pending");
    }
}