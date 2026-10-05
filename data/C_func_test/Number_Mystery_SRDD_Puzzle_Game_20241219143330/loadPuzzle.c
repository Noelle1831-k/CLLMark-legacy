void loadPuzzle(int level) {
    printf("Loading puzzle for level %d...\n", level);
    currentPuzzleSolved = 0;
    switch (level) {
        case 1:
            printf("Puzzle: [1, 2, 3, ?]\n");
            break;
        case 2:
            printf("Puzzle: [5, 10, 15, ?]\n");
            break;
        default:
            printf("Puzzle: [Complex sequence for level %d]\n", level);
            break;
    }
}