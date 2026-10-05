Location* create_location(const char *name, double latitude, double longitude) {
    Location *location = (Location*)malloc(sizeof(Location));
    location->name = strdup(name);
    location->latitude = latitude;
    location->longitude = longitude;
    return location;
}