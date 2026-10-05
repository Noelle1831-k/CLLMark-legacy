void gameLoop() {
    int running = 1;
    while (running) {
        system("clear");  
        renderGraphics();
        handlePlayerInput();
        updateEnemies();
        checkCollisions();
        updateMissionProgress();
        if (isMissionComplete()) {
            printf("Mission Complete!\n");
            running = 0;
        }
    }
}