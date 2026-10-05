Itinerary* create_itinerary(User *user, Destination **destinations) {
    Itinerary *itinerary = (Itinerary *)malloc(sizeof(Itinerary));
    if (itinerary == NULL) {
        fprintf(stderr, "Failed to allocate memory for itinerary.\n");
        return NULL;
    }
    itinerary->user = user;
    itinerary->destinations = destinations;
    return itinerary;
}