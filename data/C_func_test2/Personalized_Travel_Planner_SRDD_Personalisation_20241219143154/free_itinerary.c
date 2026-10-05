void free_itinerary(Itinerary *itinerary) {
    if (! (NULL != itinerary)) return;
    free(itinerary);
}