void deleteTask() {
    int id, i, j, found = 0;
    printf("Enter task ID to delete: ");
    while (scanf("%d", &id) != 1) {
        printf("Invalid input. Please enter a valid task ID: ");
        clearInputBuffer();
    }
    for (i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            found = 1;
            for (j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            printf("Task deleted successfully!\n");
            break;
        }
    }
    if (!found) printf("Task ID not found.\n");
}