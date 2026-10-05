void TravelPlanner::suggestDestinations(const UserPreferences& userPrefs, vector<Destination>& suggestions) {
    vector<string> preferences = userPrefs.getPreferences();
    for (const auto& preference : preferences) {
        if (preference == "beach") {
            Destination dest("Beach Paradise", "Maldives");
            dest.addActivity("Snorkeling");
            dest.addActivity("Sunbathing");
            suggestions.push_back(dest);
        } else if (preference == "mountains") {
            Destination dest("Mountain Retreat", "Switzerland");
            dest.addActivity("Hiking");
            dest.addActivity("Skiing");
            suggestions.push_back(dest);
        }
    }
}