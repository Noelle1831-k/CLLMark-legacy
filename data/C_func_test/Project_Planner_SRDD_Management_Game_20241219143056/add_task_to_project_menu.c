void add_task_to_project_menu(Project *projects, int num_projects) {
    if (num_projects == 0) {
        printf("No projects available to add tasks.\n");
        return;
    }
    int project_id;
    printf("Enter project number to add task: ");
    scanf("%d", &project_id);
    if (project_id < 1 || project_id > num_projects) {
        printf("Invalid project number.\n");
        return;
    }
    add_task_to_project(&projects[project_id - 1]);
}