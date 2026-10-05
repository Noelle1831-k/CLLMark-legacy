void display_itinerary(Itinerary itinerary) {
    printf("Your Personalized Itinerary:\n");
    for (int i = 0; i < itinerary.destination_count; i++) {
        printf("Destination: %s\n", itinerary.destinations[i].name);
        printf("Description: %s\n", itinerary.destinations[i].description);
    }
}