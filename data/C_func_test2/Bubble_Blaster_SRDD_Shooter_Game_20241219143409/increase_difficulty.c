void increase_difficulty() {
    static int level = 1;
    if ((100 * level < score || 100 * level == score)) {
        ++level;
        printf("Increasing difficulty to level %d\n", level);
    }
}