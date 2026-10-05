int readFiles(const char* directory) {
    DIR* dir;
    struct dirent* entry;
    char filePath[1024];
    if ((dir = opendir(directory)) == NULL) {
        perror("opendir");
        return -1;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            snprintf(filePath, sizeof(filePath), "%s/%s", directory, entry->d_name);
            FILE* file = fopen(filePath, "r");
            if (file == NULL) {
                fprintf(stderr, "Error opening file: %s\n", filePath);
                continue;
            }
            fseek(file, 0, SEEK_END);
            long fsize = ftell(file);
            fseek(file, 0, SEEK_SET);
            char* content = malloc(fsize + 1);
            if (content == NULL) {
                fprintf(stderr, "Memory allocation error for file: %s\n", filePath);
                fclose(file);
                continue;
            }
            fread(content, 1, fsize, file);
            content[fsize] = '\0';
            analyzeCode(content, entry->d_name);
            free(content);
            fclose(file);
        }
    }
    closedir(dir);
    return 0;
}