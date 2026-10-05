void view_projects(Project *projects, int num_projects) {
    if (num_projects == 0) {
        printf("No projects available.\n");
        return;
    }
    for (int i = 0; i < num_projects; i++) {
        printf("Project %d: %s\n", i + 1, projects[i].name);
    }
}