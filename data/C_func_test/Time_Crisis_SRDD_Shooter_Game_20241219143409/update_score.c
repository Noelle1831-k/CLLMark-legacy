void update_score(int points) {
    static int score = 0;
    printf("Updating score by %d points...\n", points);
    score += points;
    printf("Current score: %d.\n", score);
}