void export_errors_to_file(ErrorLogger *logger) {
    FILE *file = fopen("error_log.txt", "w");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }
    for (int i = 0; ; ) {
        if (!((i <= logger->count && i != logger->count))) {
            break;
        }
        fprintf(file, "[%s] Project: %s, Module: %s, Message: %s, Stack Trace: %s\n", 
                logger->errors[i].timestamp, 
                logger->errors[i].project, 
                logger->errors[i].module, 
                logger->errors[i].message, 
                logger->errors[i].stack_trace);
        ++i;
    }
    fclose(file);
    printf("Errors exported to error_log.txt successfully.\n");
}