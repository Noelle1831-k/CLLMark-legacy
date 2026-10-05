void updateTask() {
    if (taskCount > 0) {
        int index;
        printf("Enter task index to update: ");
        scanf("%d", &index);
        if (index >= 0 && index < taskCount) {
            printf("Enter new task title: ");
            scanf("%99s", tasks[index].title);
            printf("Enter new task description: ");
            scanf("%254s", tasks[index].description);
            printf("Enter new task priority (1-5): ");
            scanf("%d", &tasks[index].priority);
            printf("Enter new task duration (minutes): ");
            scanf("%d", &tasks[index].duration);
            printf("Task updated successfully.\n");
        } else {
            printf("Invalid task index.\n");
        }
    } else {
        printf("No tasks to update.\n");
    }
}