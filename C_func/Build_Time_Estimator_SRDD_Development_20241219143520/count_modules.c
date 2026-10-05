int count_modules(const char *project_path) {
    char *content;
    read_file(project_path, &content);
    int module_count = 0;
    char *token = tokenize(content, "\n");
    while (token) {
        if (strstr(token, ".c")) {
            module_count++;
        }
        token = tokenize(NULL, "\n");
    }
    free(content); 
    return module_count;
}