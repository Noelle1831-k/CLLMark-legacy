void handleLogistics(FestivalManager *manager) {
    printf("Handling logistics...\n");
    for (int i = 0; i < 3; i++) {
        printf("Location: %s, Capacity: %d\n", getLocationDetails(&manager->locations[i]), manager->locations[i].capacity);
    }
}