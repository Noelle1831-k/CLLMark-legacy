void initializeGame() {
    srand(time(NULL));
    loadWordList();
    printf("Welcome to the Word Grid Challenge!\n");
    printf("Rules: Form words by connecting adjacent letters (horizontal, vertical, or diagonal).\n");
}