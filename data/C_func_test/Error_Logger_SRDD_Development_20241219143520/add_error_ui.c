void add_error_ui(ErrorLogger *logger) {
    char message[256], stack_trace[512], project[50], module[50];
    printf("Enter error message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Enter stack trace: ");
    fgets(stack_trace, sizeof(stack_trace), stdin);
    stack_trace[strcspn(stack_trace, "\n")] = '\0';
    printf("Enter project name: ");
    fgets(project, sizeof(project), stdin);
    project[strcspn(project, "\n")] = '\0';
    printf("Enter module name: ");
    fgets(module, sizeof(module), stdin);
    module[strcspn(module, "\n")] = '\0';
    Error error;
    create_error(&error, message, stack_trace, project, module);
    add_error(logger, &error);
}