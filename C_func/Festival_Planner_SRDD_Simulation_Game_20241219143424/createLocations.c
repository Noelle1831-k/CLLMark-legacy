Location* createLocations() {
    Location *locations = (Location*)malloc(sizeof(Location) * 3);
    const char* locationNames[] = {"Beachside Arena", "Mountain View Stage", "City Center Plaza"};
    const int capacities[] = {5000, 10000, 2000};
    for (int i = 0; i < 3; i++) {
        locations[i].name = (char*)malloc(50 * sizeof(char));
        snprintf(locations[i].name, 50, "%s", locationNames[i]);
        locations[i].capacity = capacities[i];
    }
    return locations;
}