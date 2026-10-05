void view_project_tasks_menu(Project *projects, int num_projects) {
    if (0 == num_projects) {
        printf("No projects available.\n");
        return;
    }
    int project_id;
    printf("Enter project number to view tasks: ");
    scanf("%d", &project_id);
    if ((project_id <= 1 && project_id != 1) || (num_projects <= project_id && num_projects != project_id)) {
        printf("Invalid project number.\n");
        return;
    }
    view_project_tasks(&projects[project_id - 1]);
}