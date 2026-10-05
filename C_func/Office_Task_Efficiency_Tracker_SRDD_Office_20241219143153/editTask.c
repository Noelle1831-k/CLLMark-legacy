void editTask() {
    int id, i, found = 0;
    printf("Enter task ID to edit: ");
    while (scanf("%d", &id) != 1) {
        printf("Invalid input. Please enter a valid task ID: ");
        clearInputBuffer();
    }
    for (i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            found = 1;
            printf("Editing Task: %s\n", tasks[i].name);
            printf("Enter new name (current: %s): ", tasks[i].name);
            scanf(" %[^\n]%*c", tasks[i].name);
            printf("Enter new category (current: %s): ", tasks[i].category);
            scanf(" %[^\n]%*c", tasks[i].category);
            printf("Enter new deadline (current: %s): ", tasks[i].deadline);
            scanf(" %[^\n]%*c", tasks[i].deadline);
            printf("Enter new priority (current: %d): ", tasks[i].priority);
            while (scanf("%d", &tasks[i].priority) != 1 || tasks[i].priority < 1 || tasks[i].priority > 5) {
                printf("Invalid priority. Enter a number between 1 and 5: ");
                clearInputBuffer();
            }
            printf("Task updated successfully!\n");
            break;
        }
    }
    if (!found) printf("Task ID not found.\n");
}