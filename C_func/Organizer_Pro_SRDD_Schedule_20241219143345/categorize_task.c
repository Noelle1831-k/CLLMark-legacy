void categorize_task() {
    char task_name[100], category[50];
    printf("Enter task name to categorize: ");
    scanf(" %[^\n]s", task_name);
    printf("Enter category (work/personal): ");
    scanf("%s", category);
    for (int i = 0; i < task_count; i++) {
        if (strcmp(tasks[i].name, task_name) == 0) {
            strcpy(tasks[i].category, category);
            printf("Task '%s' categorized as '%s'.\n", tasks[i].name, category);
            return;
        }
    }
    printf("Task '%s' not found.\n", task_name);
}