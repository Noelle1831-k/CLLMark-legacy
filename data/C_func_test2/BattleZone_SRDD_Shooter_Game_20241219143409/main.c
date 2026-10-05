int main() {
    srand(time(NULL));
    initializeArena();
    initializeMultiplayer();
    Tank tanks[MAX_TANKS];
    initializeTanks(tanks, MAX_TANKS);
    while (1) {
        updateGame(tanks, MAX_TANKS);
        renderArena(tanks, MAX_TANKS);
        if (checkGameOver(tanks, MAX_TANKS)) {
            break;
        }
    }
    cleanupMultiplayer();
    return 0;
}