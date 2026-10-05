void simulateCompetition(Challenge *challenge) {
    challenge->competitionLevel = rand() % 5; 
    printf("Competition level: %d\n", challenge->competitionLevel);
}