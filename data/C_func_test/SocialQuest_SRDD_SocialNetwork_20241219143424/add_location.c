void add_location(ScavengerHunt *hunt, Location *location) {
    hunt->locations = (Location**)realloc(hunt->locations, sizeof(Location*) * (hunt->num_locations + 1));
    hunt->locations[hunt->num_locations] = location;
    hunt->num_locations++;
}