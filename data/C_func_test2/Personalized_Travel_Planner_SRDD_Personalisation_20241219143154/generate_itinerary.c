void generate_itinerary(Itinerary *itinerary) {
    if (itinerary == NULL) return;
    printf("Generating itinerary for %s...\n", itinerary->user->name);
    for (int i = 0; itinerary->destinations[i] != NULL; i++) {
        printf("Destination: %s\n", itinerary->destinations[i]->name);
        printf("Activities:\n");
        for (int j = 0; itinerary->destinations[i]->activities[j] != NULL; j++) {
            printf("- %s\n", itinerary->destinations[i]->activities[j]);
        }
    }
}