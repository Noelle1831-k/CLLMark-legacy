int main() {
    int numPlayers;
    int timePerTurn;
    printf("Welcome to the Board Game Turn Timer!\n");
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);
    printf("Enter the time limit per turn (in seconds): ");
    scanf("%d", &timePerTurn);
    initializeGame(numPlayers, timePerTurn);
    startGame();
    endGame();
    return 0;
}