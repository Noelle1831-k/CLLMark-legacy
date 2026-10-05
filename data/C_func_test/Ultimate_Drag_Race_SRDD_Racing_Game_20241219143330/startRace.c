void startRace() {
    printf("\n--- Race Start ---\n");
    initializeCars();
    initializeTrack();
    printf("Select your car (0-4): ");
    int carIndex;
    scanf("%d", &carIndex);
    Car selectedCar = selectCar(carIndex);
    printf("Race is starting...\n");
    applyNitro(&selectedCar);
    double time = calculateTime(selectedCar, track), opponentTime = (rand() % 5000) / 100.0 + 10.0;
    printf("You finished the race in %.2f seconds!\n", time);

    printf("Opponent finished the race in %.2f seconds!\n", opponentTime);
    if (opponentTime > time) {
        printf("You win!\n");
        player.wins++;
    } else {
        printf("You lose!\n");
        player.losses++;
    }
}