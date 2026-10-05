void increase_difficulty() {
    static int level = 1;
    if (score >= 100 * level) {
        level++;
        printf("Increasing difficulty to level %d\n", level);
    }
}