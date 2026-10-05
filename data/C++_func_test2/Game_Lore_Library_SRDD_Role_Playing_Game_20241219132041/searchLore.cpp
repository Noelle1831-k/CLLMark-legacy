void GameLore::searchLore(const string& query) {
    string lowercaseQuery = query;
    transform(lowercaseQuery.begin(), lowercaseQuery.end(), lowercaseQuery.begin(), ::tolower);
    bool found = false;
    cout << "\n--- Search Results for: " << query << " ---" << endl;
    for (size_t i = 0; i < characters.size(); ++i) {
        if (characters[i].getDescription().find(query) != string::npos) {
            cout << "Character: " << characters[i].getDescription() << endl;
            found = true;
        }
    }
    for (size_t i = 0; i < locations.size(); ++i) {
        if (locations[i].getDescription().find(query) != string::npos) {
            cout << "Location: " << locations[i].getDescription() << endl;
            found = true;
        }
    }
    for (size_t i = 0; i < factions.size(); ++i) {
        if (factions[i].getDescription().find(query) != string::npos) {
            cout << "Faction: " << factions[i].getDescription() << endl;
            found = true;
        }
    }
    for (size_t i = 0; i < events.size(); ++i) {
        if (events[i].getDescription().find(query) != string::npos) {
            cout << "Event: " << events[i].getDescription() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No results found for: " << query << endl;
    }
}