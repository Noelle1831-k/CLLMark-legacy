void Itinerary::generateItinerary(const UserPreferences& prefs, const vector<Destination>& allDestinations) {
    vector<Destination> filteredDestinations;
    for (size_t i = 0; i < allDestinations.size(); i++) {
        vector<string> filteredActivities = filterActivities(allDestinations[i].getActivities(), prefs.getPreferences());
        if (!filteredActivities.empty()) {
            Destination dest = allDestinations[i];
            for (size_t j = 0; j < filteredActivities.size(); j++) {
                dest.addActivity(filteredActivities[j]);
            }
            filteredDestinations.push_back(dest);
        }
    }
    sortDestinations(filteredDestinations);
    destinations = filteredDestinations;
}