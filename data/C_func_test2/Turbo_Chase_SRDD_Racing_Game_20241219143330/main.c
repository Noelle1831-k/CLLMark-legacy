int main() {
    srand(time(0)); 
    Player player = initializePlayer();
    Vehicle vehicle = chooseVehicle();
    CityMap city = initializeCity();
    PoliceForce police = initializePolice();
    printf("Welcome to Turbo Chase!\n");
    printf("Your mission: Outrun the police and win the race!\n");
    int gameTick = 0;
    while (gameTick < MAX_GAME_TICKS) {
        printf("\nGame Tick: %d\n", gameTick);
        updatePlayer(&player, &vehicle, &city);
        updatePolice(&police, &player, &city);
        handlePhysics(&player, &vehicle, &city);
        renderGraphics(&player, &vehicle, &city, &police);
        if (checkVictory(&player, &city)) {
            printf("Congratulations! You outran the police and won the race!\n");
            break;
        }
        if (checkCapture(&police, &player)) {
            printf("Game Over! The police caught you.\n");
            break;
        }
        gameTick++;
    }
    printf("Thanks for playing Turbo Chase!\n");
    return 0;
}