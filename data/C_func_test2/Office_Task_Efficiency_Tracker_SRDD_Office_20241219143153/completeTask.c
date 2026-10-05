void completeTask() {
    int id, i, found = 0;
    printf("Enter task ID to mark as completed: ");
    while (scanf("%d", &id) != 1) {
        printf("Invalid input. Please enter a valid task ID: ");
        clearInputBuffer();
    }
    for (i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
            printf("Task marked as completed.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Task ID not found.\n");
}