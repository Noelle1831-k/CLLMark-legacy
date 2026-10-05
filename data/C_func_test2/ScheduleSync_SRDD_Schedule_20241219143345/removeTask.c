void removeTask() {
    if (taskCount > 0) {
        int index;
        printf("Enter task index to remove: ");
        scanf("%d", &index);
        if (index >= 0 && index < taskCount) {
            for (int i = index; i < taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            printf("Task removed successfully.\n");
        } else {
            printf("Invalid task index.\n");
        }
    } else {
        printf("No tasks to remove.\n");
    }
}