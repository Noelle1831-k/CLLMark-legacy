FestivalManager* createFestivalManager() {
    FestivalManager *manager = (FestivalManager*)malloc(sizeof(FestivalManager));
    manager->artists = createArtists();
    manager->genres = createGenres();
    manager->locations = createLocations();
    manager->ticketSales = createTicketSales();
    manager->challenges = createChallenges();
    return manager;
}