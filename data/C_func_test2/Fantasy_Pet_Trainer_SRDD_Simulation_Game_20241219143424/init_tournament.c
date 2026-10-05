void init_tournament() {
    printf("Initializing tournament...\n");
    strcpy(currentTournament.tournament_name, "Grand Championship");
    currentTournament.prize = 1000;
    printf("Tournament initialized: %s\n", currentTournament.tournament_name);
}