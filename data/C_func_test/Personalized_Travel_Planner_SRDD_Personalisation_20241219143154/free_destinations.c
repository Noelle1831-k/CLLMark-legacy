void free_destinations(Destination **destinations) {
    if (destinations == NULL) return;
    for (int i = 0; destinations[i] != NULL; i++) {
        free_destination(destinations[i]);
    }
    free(destinations);
}