void create_error(Error *error, const char *message, const char *stack_trace, const char *project, const char *module) {
    time_t now = time(NULL);
    strftime(error->timestamp, sizeof(error->timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    strncpy(error->message, message, sizeof(error->message) - 1);
    error->message[sizeof(error->message) - 1] = '\0';
    strncpy(error->stack_trace, stack_trace, sizeof(error->stack_trace) - 1);
    error->stack_trace[sizeof(error->stack_trace) - 1] = '\0';
    strncpy(error->project, project, sizeof(error->project) - 1);
    error->project[sizeof(error->project) - 1] = '\0';
    strncpy(error->module, module, sizeof(error->module) - 1);
    error->module[sizeof(error->module) - 1] = '\0';
}