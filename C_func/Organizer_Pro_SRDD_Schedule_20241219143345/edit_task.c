void edit_task() {
    char task_name[100];
    printf("Enter task name to edit: ");
    scanf(" %[^\n]s", task_name);
    for (int i = 0; i < task_count; i++) {
        if (strcmp(tasks[i].name, task_name) == 0) {
            printf("Editing task '%s'.\n", tasks[i].name);
            printf("Enter new description: ");
            scanf(" %[^\n]s", tasks[i].description);
            printf("Enter new category: ");
            scanf("%s", tasks[i].category);
            printf("Task '%s' updated successfully.\n", tasks[i].name);
            return;
        }
    }
    printf("Task '%s' not found.\n", task_name);
}