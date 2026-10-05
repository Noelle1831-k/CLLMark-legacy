void generate_itinerary(UserPreferences user_preferences, Itinerary *itinerary) {
    printf("Generating your personalized itinerary...\n");
    itinerary->destination_count = 0;
    for (int i = 0; i < DESTINATION_COUNT; i++) {
        if (user_preferences.interests[i]) {
            itinerary->destinations[itinerary->destination_count++] = destinations[i];
        }
    }
}