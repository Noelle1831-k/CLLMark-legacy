int main(int argc, char *argv[]) {
    initializeGame();
    while (isGameRunning()) {
        displayCurrentPuzzle();
        char input[100];
        getUserInput(input, sizeof(input));
        if (processInput(input)) {
            if (isPuzzleSolved()) {
                advanceToNextLevel();
            }
        } else {
            printf("Invalid input. Try again.\n");
        }
    }
    finalizeGame();
    return 0;
}