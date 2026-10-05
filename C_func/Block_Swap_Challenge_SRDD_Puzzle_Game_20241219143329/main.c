int main() {
    int moves, level, score = 0;
    initializeGame(&moves, &level, &score);
    while (1) {
        playLevel(level, &moves, &score);
        if (moves <= 0) {
            printf("Game Over! Final Score: %d\n", score);
            break;
        }
        printf("Level %d Complete! Moving to Level %d...\n", level, level + 1);
        level++;
    }
    return 0;
}