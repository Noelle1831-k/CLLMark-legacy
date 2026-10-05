void initializeGame() {
    printf("Initializing game...\n");
    srand(time(0));  
    initializeGraphics();
    initializeGameState();
}