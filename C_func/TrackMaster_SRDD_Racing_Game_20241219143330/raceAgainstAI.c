void raceAgainstAI() {
    printf("Racing against AI...\n");
    int aiSpeed = rand() % 100 + 50;
    int playerSpeed = rand() % 100 + 50; 
    int aiSkill = rand() % 5 + 1; 
    printf("Player speed: %d km/h\n", playerSpeed);
    printf("AI speed: %d km/h\n", aiSpeed);
    printf("AI skill level: %d\n", aiSkill);
    if (playerSpeed > aiSpeed + aiSkill) {
        printf("You won the race!\n");
    } else {
        printf("You lost the race. Better luck next time!\n");
    }
}