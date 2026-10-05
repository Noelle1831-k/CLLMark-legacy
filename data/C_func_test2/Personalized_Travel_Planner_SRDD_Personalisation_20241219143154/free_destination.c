void free_destination(Destination *destination) {
    if (destination == NULL) return;
    free(destination->name);
    if (destination->activities) {
        for (int i = 0; destination->activities[i] != NULL; i++) {
            free(destination->activities[i]);
        }
        free(destination->activities);
    }
    free(destination);
}