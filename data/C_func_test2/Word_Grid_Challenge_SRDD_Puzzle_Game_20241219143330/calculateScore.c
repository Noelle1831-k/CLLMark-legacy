void calculateScore(const char *word) {
    score += strlen(word) * 10;
    printf("Current Score: %d\n", score);
}