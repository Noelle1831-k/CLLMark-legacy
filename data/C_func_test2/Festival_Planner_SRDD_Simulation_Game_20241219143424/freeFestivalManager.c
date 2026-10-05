void freeFestivalManager(FestivalManager *manager) {
    for (int i = 0; i < 10; i++) {
        free(manager->artists[i].name);
        free(manager->artists[i].genre);
    }
    free(manager->artists);
    for (int i = 0; i < 5; i++) {
        free(manager->genres[i].name);
    }
    free(manager->genres);
    for (int i = 0; i < 3; i++) {
        free(manager->locations[i].name);
    }
    free(manager->locations);
    free(manager->ticketSales);
    free(manager->challenges);
    free(manager);
}