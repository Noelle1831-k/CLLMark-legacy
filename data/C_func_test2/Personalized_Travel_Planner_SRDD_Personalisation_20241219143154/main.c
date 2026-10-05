int main() {
    User *user = load_user_data("user_data.txt");
    if (user == NULL) {
        fprintf(stderr, "Failed to load user data.\n");
        return EXIT_FAILURE;
    }
    Destination **destinations = load_destination_data("destination_data.txt");
    if (destinations == NULL) {
        fprintf(stderr, "Failed to load destination data.\n");
        free_user(user);
        return EXIT_FAILURE;
    }
    Itinerary *itinerary = create_itinerary(user, destinations);
    if (itinerary == NULL) {
        fprintf(stderr, "Failed to create itinerary.\n");
        free_user(user);
        free_destinations(destinations);
        return EXIT_FAILURE;
    }
    generate_itinerary(itinerary);
    free_itinerary(itinerary);
    free_user(user);
    free_destinations(destinations);
    return EXIT_SUCCESS;
}