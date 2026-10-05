void view_project_tasks(Project *project) {
    if (project->num_tasks == 0) {
        printf("No tasks for this project.\n");
        return;
    }
    for (int i = 0; i < project->num_tasks; i++) {
        view_task(&project->tasks[i]);
    }
}