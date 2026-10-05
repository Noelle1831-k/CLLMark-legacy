void initializeGame() {
    printf("Welcome to Number Mystery!\n");
    srand(time(NULL)); 
    currentLevel = 1;
    loadPuzzle(currentLevel);
}