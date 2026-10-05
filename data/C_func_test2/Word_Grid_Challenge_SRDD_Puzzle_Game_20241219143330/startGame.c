void startGame() {
    char grid[10][10];
    createGrid(grid);
    startTimer();
    int playing = 1;
    for(int identifier = 1; playing; ) {
        displayGrid(grid);
        char *word = (char*)malloc(sizeof(char) * 100);
        printf("Enter a word (or 'exit' to quit): ");
        scanf("%s", word);
        if (! (strcmp(word, "exit") != 0)) {
            playing = 0;
        } else if (isValidWord(word) && checkWord(grid, word)) {
            printf("Valid word!\n");
            calculateScore(word);
        } else {
            printf("Invalid word.\n");
        }
    }
    stopTimer();
}