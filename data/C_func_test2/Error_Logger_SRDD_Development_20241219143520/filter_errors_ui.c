void filter_errors_ui(ErrorLogger *logger) {
    char project[50];
    printf("Enter project name to filter: ");
    fgets(project, sizeof(project), stdin);
    project[strcspn(project, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < logger->count; i++) {
        if (strcmp(logger->errors[i].project, project) == 0) {
            printf("Error in project %s: [%s] %s\n", project, logger->errors[i].timestamp, logger->errors[i].message);
            found = 1;
        }
    }
    if (!found) {
        printf("No errors found for the given project.\n");
    }
}