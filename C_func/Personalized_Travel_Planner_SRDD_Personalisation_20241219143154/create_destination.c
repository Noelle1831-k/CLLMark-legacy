Destination* create_destination(char *name, char **activities) {
    Destination *destination = (Destination *)malloc(sizeof(Destination));
    if (destination == NULL) {
        fprintf(stderr, "Failed to allocate memory for destination.\n");
        return NULL;
    }
    destination->name = strdup(name);
    if (destination->name == NULL) {
        fprintf(stderr, "Failed to allocate memory for destination name.\n");
        free(destination);
        return NULL;
    }
    destination->activities = activities;
    return destination;
}