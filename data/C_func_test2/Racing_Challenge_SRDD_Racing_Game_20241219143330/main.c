int main() {
    srand(time(NULL)); 
    printf("Welcome to Racing Challenge!\n");
    Game *game = initializeGame();
    selectTrack(game);
    selectVehicle(game);
    startRace(game);
    freeGame(game);
    return 0;
}