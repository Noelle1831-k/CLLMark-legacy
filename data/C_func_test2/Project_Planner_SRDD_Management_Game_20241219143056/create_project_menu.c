void create_project_menu(Project **projects, int *num_projects) {
    char *name = (char*)malloc(sizeof(char) * 50);
    printf("Enter project name: ");
    scanf("%s", name);
    *projects = realloc(*projects, sizeof(Project) * (*num_projects + 1));
    create_project(*projects + *num_projects, name);
    (*num_projects)++;
    printf("Project created successfully.\n");
}