void GameLore::loadData() {
    cout << "Loading game lore data..." << endl;
    Character character1("Aragorn", "A skilled ranger and rightful king.");
    Character character2("Gandalf", "A powerful wizard and wise advisor.");
    characters.push_back(character1);
    characters.push_back(character2);
    Location location1("Rivendell", "A beautiful elven valley.");
    Location location2("Mordor", "A dark, volcanic region ruled by evil.");
    locations.push_back(location1);
    locations.push_back(location2);
    Faction faction1("The Fellowship", "A group of heroes united to destroy the One Ring.");
    Faction faction2("The Orcs", "Servants of Sauron and agents of chaos.");
    factions.push_back(faction1);
    factions.push_back(faction2);
    Event event1("Battle of Helm's Deep", "A critical battle between men and orcs.");
    Event event2("Destruction of the Ring", "The climactic moment when evil is vanquished.");
    events.push_back(event1);
    events.push_back(event2);
    cout << "Game lore data loaded successfully!" << endl;
}