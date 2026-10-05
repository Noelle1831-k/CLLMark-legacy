User* load_user_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    char name[100];
    fscanf(file, "%s", name);
    char **preferences = (char **)malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++) {
        preferences[i] = (char *)malloc(100 * sizeof(char));
        fscanf(file, "%s", preferences[i]);
    }
    char **interests = (char **)malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++) {
        interests[i] = (char *)malloc(100 * sizeof(char));
        fscanf(file, "%s", interests[i]);
    }
    fclose(file);
    return create_user(name, preferences, interests);
}