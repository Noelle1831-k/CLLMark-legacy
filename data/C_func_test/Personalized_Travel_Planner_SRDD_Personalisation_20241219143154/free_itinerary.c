void free_itinerary(Itinerary *itinerary) {
    if (itinerary == NULL) return;
    free(itinerary);
}