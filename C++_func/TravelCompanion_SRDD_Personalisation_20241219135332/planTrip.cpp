void TravelPlanner::planTrip(const UserPreferences& userPrefs, Itinerary& itinerary) {
    vector<Destination> suggestions;
    suggestDestinations(userPrefs, suggestions);
    for (const auto& destination : suggestions) {
        itinerary.addDestination(destination);
    }
}