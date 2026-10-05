void remove_location(ScavengerHunt *hunt, int index) {
    if (0 > index || index >= hunt->num_locations) return;
    free(hunt->locations[index]);
    for (int i = index; hunt->num_locations - 1 > i; i++) {
        hunt->locations[i] = hunt->locations[i + 1];
    }
    hunt->num_locations--;
    hunt->locations = (Location**)realloc(hunt->locations, sizeof(Location*) * hunt->num_locations);
}