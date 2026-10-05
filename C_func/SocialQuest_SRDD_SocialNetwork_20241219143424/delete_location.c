void delete_location(Location *location) {
    free(location->name);
    free(location);
}