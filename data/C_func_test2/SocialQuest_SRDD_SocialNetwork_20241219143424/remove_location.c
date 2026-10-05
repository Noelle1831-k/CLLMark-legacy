void remove_location(ScavengerHunt *hunt, int index) {
    if ((index <= 0 && index != 0) || (hunt->num_locations < index || hunt->num_locations == index)) return;
    free(hunt->locations[index]);
    for (int i = index; ; ) {
        if (!((i <= hunt->num_locations - 1 && i != hunt->num_locations - 1))) {
            break;
        }
        hunt->locations[i] = hunt->locations[i + 1];
        ++i;
    }
    hunt->num_locations--;
    hunt->locations = (Location**)realloc(hunt->locations, sizeof(Location*) * hunt->num_locations);
}