void GameLore::displayLore() {
    cout << "\n--- Game Lore ---" << endl;
    cout << "\nCharacters:" << endl;
    for (size_t i = 0; i < characters.size(); ++i) {
        cout << " - " << characters[i].getDescription() << endl;
    }
    cout << "\nLocations:" << endl;
    for (size_t i = 0; i < locations.size(); ++i) {
        cout << " - " << locations[i].getDescription() << endl;
    }
    cout << "\nFactions:" << endl;
    for (size_t i = 0; i < factions.size(); ++i) {
        cout << " - " << factions[i].getDescription() << endl;
    }
    cout << "\nEvents:" << endl;
    for (size_t i = 0; i < events.size(); ++i) {
        cout << " - " << events[i].getDescription() << endl;
    }
}