void startGame() {
    printf("Welcome to the Target Shooter Game!\n");
    printf("Try to shoot moving targets as accurately as possible within the time limit.\n");
    printf("Each hit within the hit radius gives you 10 points. Good luck!\n\n");
    initializePlayer(&player);
    initializeTarget(&target);
    while (elapsedTime < GAME_DURATION) {
        updateGame();
        delay(1000); 
        elapsedTime++;
    }
    endGame();
}