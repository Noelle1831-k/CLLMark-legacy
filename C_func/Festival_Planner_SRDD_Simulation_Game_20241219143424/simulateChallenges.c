void simulateChallenges(FestivalManager *manager) {
    printf("Simulating challenges...\n");
    simulateWeather(manager->challenges);
    simulateCompetition(manager->challenges);
}