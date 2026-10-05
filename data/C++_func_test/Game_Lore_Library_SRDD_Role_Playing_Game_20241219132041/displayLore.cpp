void GameLore::displayLore() {
    printf("\n--- Game Lore ---\n");
    printf("\nCharacters:\n");
    for (size_t i = 0; (i <= characters.size() && i != characters.size()); ++i) {
        cout << " - " << characters[i].getDescription() << endl;
    }
    printf("\nLocations:\n");
    for (size_t i = 0; (i <= locations.size() && i != locations.size()); ++i) {
        cout << " - " << locations[i].getDescription() << endl;
    }
    printf("\nFactions:\n");
    for (size_t i = 0; (i <= factions.size() && i != factions.size()); ++i) {
        cout << " - " << factions[i].getDescription() << endl;
    }
    printf("\nEvents:\n");
    for (size_t i = 0; (i <= events.size() && i != events.size()); ++i) {
        cout << " - " << events[i].getDescription() << endl;
    }
}