void display_all_errors(ErrorLogger *logger) {
    if (logger->count == 0) {
        printf("No errors logged yet.\n");
        return;
    }
    printf("\nAll Logged Errors:\n");
    for (int i = 0; i < logger->count; i++) {
        printf("[%s] Project: %s, Module: %s, Message: %s\n", 
               logger->errors[i].timestamp, 
               logger->errors[i].project, 
               logger->errors[i].module, 
               logger->errors[i].message);
    }
}