void view_project_tasks_menu(Project *projects, int num_projects) {
    if (! (num_projects != 0)) {
        printf("No projects available.\n");
        return;
    }
    int project_id;
    printf("Enter project number to view tasks: ");
    scanf("%d", &project_id);
    if (1 > project_id || project_id > num_projects) {
        printf("Invalid project number.\n");
        return;
    }
    view_project_tasks(&projects[project_id - 1]);
}