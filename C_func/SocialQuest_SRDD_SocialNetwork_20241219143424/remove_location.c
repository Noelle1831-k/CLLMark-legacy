void remove_location(ScavengerHunt *hunt, int index) {
    if (index < 0 || index >= hunt->num_locations) return;
    free(hunt->locations[index]);
    for (int i = index; i < hunt->num_locations - 1; i++) {
        hunt->locations[i] = hunt->locations[i + 1];
    }
    hunt->num_locations--;
    hunt->locations = (Location**)realloc(hunt->locations, sizeof(Location*) * hunt->num_locations);
}