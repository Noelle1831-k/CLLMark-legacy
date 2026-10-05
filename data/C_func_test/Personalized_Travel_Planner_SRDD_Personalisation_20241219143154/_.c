Destination** load_destination_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    Destination **destinations = (Destination **)malloc(10 * sizeof(Destination *));
    for (int i = 0; i < 10; i++) {
        char name[100];
        fscanf(file, "%s", name);
        char **activities = (char **)malloc(10 * sizeof(char *));
        for (int j = 0; j < 10; j++) {
            activities[j] = (char *)malloc(100 * sizeof(char));
            fscanf(file, "%s", activities[j]);
        }
        destinations[i] = create_destination(name, activities);
    }
    fclose(file);
    return destinations;
}